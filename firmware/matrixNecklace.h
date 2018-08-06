/* matrixNecklace.h
 *
 * Header file
 *
 * Copyright 2015 - 2018 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/


#ifndef _MATRIXNECKLACE_H_
#define _MATRIXNECKLACE_H_


/* DEPENDENCIES */

// Includes from avr-libc
#include <avr/pgmspace.h>
#include <util/delay.h>

// Self Programing functions
// #include <avr/boot.h>

// Patterns file
#include "patterns.h"



/* CONSTANTS DEFINITIONS */

// Uncomment this if the matrix is upside-down
// #define invert_matrix 1


// Masks for pin registers
#ifdef invert_matrix
	// TODO: Make inverted pinout
#else
	/* === Rows === */
	#define ROW1_PORT PORTD // 0b00000100 // PD5
	#define ROW1_PIN  5
	#define ROW2_PORT PORTD // 0b00001000 // PD4
	#define ROW2_PIN  4
	#define ROW3_PORT PORTA // 0b01000000 // PA1
	#define ROW3_PIN  1
	#define ROW4_PORT PORTB // 0b00000100 // PB5
	#define ROW4_PIN  5
	#define ROW5_PORT PORTD // 0b01000000 // PD1
	#define ROW5_PIN  1
	#define ROW6_PORT PORTB // 0b00010000 // PB3
	#define ROW6_PIN  3
	#define ROW7_PORT PORTB // 0b00100000 // PB2
	#define ROW7_PIN  2
	#define ROW8_PORT PORTD // 0b00100000 // PD2
	#define ROW8_PIN  2

	/* === Columns === */
	#define COL1_PORT PORTD
	#define COL1_PIN  0
	#define COL2_PORT PORTD
	#define COL2_PIN  3
	#define COL3_PORT PORTB
	#define COL3_PIN  7
	#define COL4_PORT PORTA
	#define COL4_PIN  0
	#define COL5_PORT PORTB
	#define COL5_PIN  0
	#define COL6_PORT PORTB
	#define COL6_PIN  6
	#define COL7_PORT PORTB
	#define COL7_PIN  1
	#define COL8_PORT PORTB
	#define COL8_PIN  4
#endif


// Frames speed
#define speed1 ((uint16_t) 700)
#define speed2 ((uint16_t) 1000)





/* FUNCTIONS */

void writePattern(const uint8_t pat[8], uint8_t frames);
// Set or Clear a bit
#define sbi(reg, pos) (var |= (1<<pos))
#define cbi(reg, pos) (reg &= ~(1<<pos))




/* C PROGRAM */

#include "matrixNecklace.c"


#endif  /* !_MATRIXNECKLACE_H_ */
