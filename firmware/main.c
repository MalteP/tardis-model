// #############################################################################
// #                         --- Chameleon circuit ---                         #
// #          A light and sound controller for your own TARDIS model           #
// #############################################################################
// # main.c - Main program for light & sound effects                           #
// #############################################################################
// #              Version: 1.0 - Compiler: AVR-GCC 4.9.2 (Linux)               #
// #     (c) 2015 by Malte Pöggel - www.MALTEPOEGGEL.de - malte@poeggel.de     #
// #############################################################################
// #  This program is free software; you can redistribute it and/or modify it  #
// #   under the terms of the GNU General Public License as published by the   #
// #        Free Software Foundation; either version 3 of the License,         #
// #                  or (at your option) any later version.                   #
// #                                                                           #
// #      This program is distributed in the hope that it will be useful,      #
// #      but WITHOUT ANY WARRANTY; without even the implied warranty of       #
// #           MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            #
// #           See the GNU General Public License for more details.            #
// #                                                                           #
// #  You should have received a copy of the GNU General Public License along  #
// #      with this program; if not, see <http://www.gnu.org/licenses/>.       #
// #############################################################################

#include <avr/io.h>
#include <util/delay.h>
#include "wtv20.h"
#include "main.h"

int main( void )
 {
  uint8_t led_a, led_b;
  uint8_t snd = 0;

  // Initialize wibbly wobbly, timey wimey stuff
  wtv20_init();
  LED1_DDR |= (1<<LED1);
  LED2_DDR |= (1<<LED2);
  // Timer0 as Phase correct PWM, fCPU / 8
  TCCR0A = (1<<WGM00)|(1<<COM0A1)|(1<<COM0B1);
  TCCR0B = (1<<CS01);
  OCR0A = 0;
  OCR0B = 0;

  // Set volume to 100%
  wtv20_send(WTV20_SET_VOL&0x0007);

  // Main loop
  while(1)
   {
    // Fade up white LED
    for(led_b=0; led_b<0xFF; led_b++)
     {
      OCR0B = led_b;
      _delay_ms(2);
     }

    // Select sound and play
    wtv20_send(snd);
    _delay_ms(50);

    // Fade top LED in
    for(led_a=0; led_a<0xFF; led_a++)
     {
      OCR0A = led_a;
      _delay_ms(4);
     }

    // We still need to wait some time before checking because the busy signal
    // is also pulsed if no sound is played - so we need to check after ~1600 ms.
    waitsound:
    if(snd>0)
     {
      _delay_ms(750);
     } else {
      // In case of sound 0 we'll fade here instead of waiting for min. busy pulse
      for(led_a=0xFF; led_a>0; led_a--)
       {
        OCR0A = led_a;
        _delay_ms(4);
       }
      OCR0A = 0;
     }

    // Check if sound is still playing, else choose 0 or abort if sound is 0.
    if(!wtv20_busy())
     {
      if(snd>0)
       {
        snd=0;
        wtv20_send(snd);
        _delay_ms(50);
        goto waitsound;
       }
     } else {
      // Wait for sound to finish
      while(wtv20_busy())
       {
        if(snd==0)
         {
          // Pulse top LED on sound 0 (TARDIS)
          for(led_a=0; led_a<0xFF; led_a++) // Fade in
           {
            OCR0A = led_a;
            _delay_ms(4);
           }
          for(led_a=0xFF; led_a>0; led_a--) // Fade out
           {
            OCR0A = led_a;
            _delay_ms(4);
           }
          OCR0A = 0;
         } else {
          // Top LED just lit up on every other sound.
          OCR0A = 0xFF;
          _delay_ms(25);
         }
       }
      // Increment sound number
      snd++;
     }

    // Fade down top LED
    if(led_a>0)
     {
      for(led_a=0xFF; led_a>0; led_a--)
       {
        OCR0A = led_a;
        _delay_ms(4);
       }
     }

    // Fade down white LED
    for(led_b=0xFF; led_b>0; led_b--)
     {
      OCR0B = led_b;
      _delay_ms(2);
     }
    OCR0B = 0;
    OCR0A = 0;

   // Long delay
   _delay_ms(2000);
   _delay_ms(2000);
   }
 }
