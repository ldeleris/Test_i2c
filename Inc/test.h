/*
 * test.h
 *
 *  Created on: 16 févr. 2017
 *      Author: Laurent
 */

#ifndef TEST_H_
#define TEST_H_

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

static const unsigned char LOGO16_GLCD_HEIGHT = 16;
static const unsigned char LOGO16_GLCD_WIDTH  = 16;
static const unsigned char logo16_glcd_bmp[32] =
	{ 0x00, 0b11000000,
	  0x01, 0b11000000,
	  0x01, 0b11000000,
	  0x03, 0b11100000,
	  0b11110011, 0b11100000,
	  0b11111110, 0b11111000,
	  0b01111110, 0b11111111,
	  0b00110011, 0b10011111,
	  0b00011111, 0b11111100,
	  0b00001101, 0b01110000,
	  0b00011011, 0b10100000,
	  0b00111111, 0b11100000,
	  0b00111111, 0b11110000,
	  0b01111100, 0b11110000,
	  0b01110000, 0b01110000,
	  0x00, 0x30 };

class Test {
 public:
	Test(Adafruit_SSD1306 *lcd);
	void loop(void);
	void testdrawbitmap(void);
	void testdrawchar(void);
	void testdrawcircle(void);
	void testfillrect(void);
	void testdrawtriangle(void);
	void testfilltriangle(void);
	void testdrawroundrect(void);
	void testfillroundrect(void);
	void testdrawrect(void);
	void testdrawline(void);
	void testscrolltext(void);
 private:
	static const unsigned char NUMFLAKES = 10;
	static const unsigned char XPOS = 0;
	static const unsigned char YPOS = 1;
	static const unsigned char DELTAY = 2;
	Adafruit_SSD1306 *ptrLcd;

};




#endif /* TEST_H_ */
