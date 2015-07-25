// #############################################################################
// #                         --- Chameleon circuit ---                         #
// #          A light and sound controller for your own TARDIS model           #
// #############################################################################
// # wtv20.h - Library for the WTV20SD sound module (Header)                   #
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

#ifndef WTV20_H
 #define WTV20_H
 
 #define WTV20_DDR_RST   DDRA
 #define WTV20_PORT_RST  PORTA
 #define WTV20_RST       PA1

 #define WTV20_DDR_DATA  DDRA
 #define WTV20_PORT_DATA PORTA
 #define WTV20_DATA      PA3

 #define WTV20_DDR_CLK   DDRA
 #define WTV20_PORT_CLK  PORTA
 #define WTV20_CLK       PA0

 #define WTV20_DDR_BUSY  DDRA
 #define WTV20_PORT_BUSY PORTA
 #define WTV20_PIN_BUSY  PINA
 #define WTV20_BUSY      PA2

 #define WTV20_SET_VOL   0xFFF0

 void wtv20_init( void );
 void wtv20_send( uint16_t data );
 uint8_t wtv20_busy( void );

#endif
