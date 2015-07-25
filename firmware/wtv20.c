// #############################################################################
// #                         --- Chameleon circuit ---                         #
// #          A light and sound controller for your own TARDIS model           #
// #############################################################################
// # wtv20.c - Library for the WTV20SD sound module                            #
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

void wtv20_init()
 {
  // Set DDR
  WTV20_DDR_RST   |=  (1<<WTV20_RST);
  WTV20_DDR_DATA  |=  (1<<WTV20_DATA);
  WTV20_DDR_CLK   |=  (1<<WTV20_CLK);
  WTV20_DDR_BUSY  &= ~(1<<WTV20_BUSY);
  // Set Ports
  WTV20_PORT_RST  |=  (1<<WTV20_RST);
  WTV20_PORT_DATA |=  (1<<WTV20_DATA);
  WTV20_PORT_CLK  |=  (1<<WTV20_CLK);
  WTV20_PORT_BUSY |=  (1<<WTV20_BUSY);
  // Pulse Reset
  WTV20_PORT_RST  &=  ~(1<<WTV20_RST);
  _delay_ms(5);
  WTV20_PORT_RST  |=  (1<<WTV20_RST);
  _delay_ms(300);
 }


void wtv20_send( uint16_t data )
 {
  uint8_t i;
  WTV20_PORT_CLK &= ~(1<<WTV20_CLK);
  _delay_ms(2);
  for(i=16; i>0; i--)
   {
    if(data&0x8000)
     {
      WTV20_PORT_DATA |= (1<<WTV20_DATA);
     } else {
      WTV20_PORT_DATA &= ~(1<<WTV20_DATA);
     }
    WTV20_PORT_CLK  &= ~(1<<WTV20_CLK);
    _delay_us(100);
    WTV20_PORT_CLK  |= (1<<WTV20_CLK);
    _delay_us(100);
    data<<=1;
   }
 }


uint8_t wtv20_busy( void )
 {
  if(WTV20_PIN_BUSY&(1<<WTV20_BUSY)) return 1;
  return 0;
 }
