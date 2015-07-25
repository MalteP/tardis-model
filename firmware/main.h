// #############################################################################
// #                         --- Chameleon circuit ---                         #
// #          A light and sound controller for your own TARDIS model           #
// #############################################################################
// # main.h - Main program for light & sound effects (Header)                  #
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

#ifndef MAIN_H
 #define MAIN_H
 
 #define LED1_DDR  DDRB
 #define LED1_PORT PORTB
 #define LED1      PB2

 #define LED2_DDR  DDRA
 #define LED2_PORT PORTA
 #define LED2      PA7

#endif
