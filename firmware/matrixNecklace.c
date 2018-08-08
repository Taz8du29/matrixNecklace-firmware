/* matrixNecklace.cpp
 *
 * Main program file
 *
 * Copyright 2015 - 2018 (C) Taz8du29
 * Refer to LICENSE.MD for more infos about copyright
*/



// Used fuse bits : Self Programming enabled, 8Mhz clock divided by 8
// -U lfuse:w:0x64:m -U hfuse:w:0xdf:m -U efuse:w:0xfe:m


#ifndef _MATRIXNECKLACE_C_
#define _MATRIXNECKLACE_C_

#include "matrixNecklace.h"


/* MAIN FUNCTION DEFINITIONS */

void loadBuffer(const uint8_t pat[8])
{
	for(uint8_t i = 0; i < 8; i++) {
		framebuffer[i] = pgm_read_byte(pat + i);
	}
}

// Write a specific number of times the desired pattern
// TODO : improve timings efficiency (and power ?)
void playPattern(uint16_t frames)
{
	for(uint16_t x = 0; x < frames; x++) {
		for(uint8_t i = 0; i < 8; i++) {
			// Set all pins HIGH
			PORTA = 0x03;
			PORTB = 0xFF;
			PORTD = 0x7F;

			// Enable the current row
			switch (i) {
				case 0:	cbi(ROW1_PORT, ROW1_PIN); break;
				case 1:	cbi(ROW2_PORT, ROW2_PIN); break;
				case 2:	cbi(ROW3_PORT, ROW3_PIN); break;
				case 3:	cbi(ROW4_PORT, ROW4_PIN); break;
				case 4:	cbi(ROW5_PORT, ROW5_PIN); break;
				case 5:	cbi(ROW6_PORT, ROW6_PIN); break;
				case 6:	cbi(ROW7_PORT, ROW7_PIN); break;
				case 7:	cbi(ROW8_PORT, ROW8_PIN); break;
			}

			// Enable columns one by one
			if (!(framebuffer[i] & 0x01)) { cbi(COL1_PORT, COL1_PIN); }
			if (!(framebuffer[i] & 0x02)) { cbi(COL2_PORT, COL2_PIN); }
			if (!(framebuffer[i] & 0x04)) { cbi(COL3_PORT, COL3_PIN); }
			if (!(framebuffer[i] & 0x08)) { cbi(COL4_PORT, COL4_PIN); }
			if (!(framebuffer[i] & 0x10)) { cbi(COL5_PORT, COL5_PIN); }
			if (!(framebuffer[i] & 0x20)) { cbi(COL6_PORT, COL6_PIN); }
			if (!(framebuffer[i] & 0x40)) { cbi(COL7_PORT, COL7_PIN); }
			if (!(framebuffer[i] & 0x80)) { cbi(COL8_PORT, COL8_PIN); }

			// Delay ON
			_delay_us(250);

			// Set all pins LOW
			PORTA = 0x00;
			PORTB = 0x00;
			PORTD = 0x00;

			// Delay OFF
			_delay_us(750);
		}
	}
}



/* MAIN PROGRAM */

int main(void)
{
	// Define direction registers, all outputs
	DDRA = 0x03;
	DDRB = 0xFF;
	DDRD = 0x7F;

	// Set all pins LOW
	PORTA = 0x00;
	PORTB = 0x00;
	PORTD = 0x00;

	// Wait a bit
	_delay_ms(1000);

	// counters
	uint8_t cnt1 = 0; // Frame counter
	uint8_t cnt2 = 0; // Pattern counter

	// Infinite loop !!
	while(1)
	{
		// When cnt1 arrives at 0, load next patern and increment cnt2
		if (cnt1 == 0) {
			switch (cnt2) {
				case 0:	loadBuffer(bat_00); break;
				case 1:	loadBuffer(bat_20); break;
				case 2:	loadBuffer(bat_40); break;
				case 3:	loadBuffer(bat_60); break;
				case 4:	loadBuffer(bat_80); break;
				case 5:	loadBuffer(bat_100); break;
				case 6:	loadBuffer(SI1_On); break;
				case 7:	loadBuffer(SI1_Off); break;
			}

			cnt2++;
			if (cnt2 > 7) { cnt2 = 0; }
		}

		playPattern(speed1);

		// Increment frame counter
		cnt1++;

		// Battery animation
		/* for(uint8_t x = 0; x < 15; x++) {
			writePattern(bat_00, speed1);
			writePattern(bat_20, speed1);
			writePattern(bat_40, speed1);
			writePattern(bat_60, speed1);
			writePattern(bat_80, speed1);
			writePattern(bat_100, speed1);
		} */

		// Space Invaders 1 animation
		/* for(uint8_t x = 0; x < 20; x++) {
			writePattern(SI1_On, speed2);
			writePattern(SI1_Off, speed2);
		} */

		// Space Invaders 2 animation
		/* for(uint8_t x = 0; x < 20; x++) {
			writePattern(SI2_On, speed2);
			writePattern(SI2_Off, speed2);
		} */

		// Other stuff
		/*
		for(uint8_t x = 0; x < 10; x++) {
			writePattern(heart, speed2);
		}

		for(uint8_t x = 0; x < 10; x++) {
			writePattern(smile, speed2);
		}

		for(uint8_t x = 0; x < 10; x++) {
			writePattern(clock, speed2);
		}
		*/
	}
}


#endif  /* !_MATRIXNECKLACE_C_ */
