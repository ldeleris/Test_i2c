/*
 * test.cpp
 *
 *  Created on: 16 févr. 2017
 *      Author: Laurent
 */

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/
#include <algorithm>
#include <string.h>
#include <random>
#include <ctime>
#include "test.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

void Test::loop(void)
{
  // Clear the buffer.
  ptrLcd->clearDisplay();
  //ptrLcd->affiche_logo();
  //ptrLcd->display();
  //HAL_Delay(10000);
  // draw a single pixel
  ptrLcd->drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw many lines
  testdrawline();
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw rectangles
  testdrawrect();
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw multiple rectangles
  testfillrect();
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw mulitple circles
  testdrawcircle();
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw a white circle, 10 pixel radius
  ptrLcd->fillCircle(ptrLcd->width()/2, ptrLcd->height()/2, 10, WHITE);
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  testdrawroundrect();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  testfillroundrect();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  testdrawtriangle();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  testfilltriangle();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw the first ~12 characters in the font
  testdrawchar();
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // draw scrolling text
  testscrolltext();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // text display tests
  ptrLcd->setTextSize(1);
  ptrLcd->setTextColor(WHITE);
  ptrLcd->setCursor(0,0);
  ptrLcd->println("Hello, world!");
  ptrLcd->setTextColor(BLACK, WHITE); // 'inverted' text
  ptrLcd->println(3.141592);
  ptrLcd->setTextSize(2);
  ptrLcd->setTextColor(WHITE);
  ptrLcd->print("0x"); ptrLcd->println(0xDEADBEEF, HEX);
  ptrLcd->display();
  HAL_Delay(2000);
  ptrLcd->clearDisplay();

  // miniature logo16_glcd_bmp display
  ptrLcd->drawBitmap(30, 16,  logo16_glcd_bmp, 16, 16, 1);
  ptrLcd->display();
  //HAL_Delay(1);

  // invert the display
  ptrLcd->invertDisplay(true);
  HAL_Delay(1000);
  ptrLcd->invertDisplay(false);
  HAL_Delay(1000);
  ptrLcd->clearDisplay();

  // draw a logo16_glcd_bmp icon and 'animate' movement
  testdrawbitmap();
}

Test::Test(Adafruit_SSD1306 *lcd)
{
	ptrLcd = lcd;
}

void Test::testdrawbitmap(void)
{
  uint8_t icons[NUMFLAKES][3];

  // initialize
  srand(time(0));
  for (uint8_t f=0; f< NUMFLAKES; f++)
  {
    icons[f][XPOS] = rand() % ptrLcd->width();
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = (rand() % 20) + 1;
  }

  while (1) {
    // draw each icon
    for (uint8_t f=0; f< NUMFLAKES; f++) {
    	ptrLcd->drawBitmap(icons[f][XPOS], icons[f][YPOS],
    			logo16_glcd_bmp, LOGO16_GLCD_WIDTH, LOGO16_GLCD_HEIGHT, WHITE);
    }
    ptrLcd->display();
    HAL_Delay(5);

    // then erase it + move it
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      ptrLcd->drawBitmap(icons[f][XPOS], icons[f][YPOS],
    		  logo16_glcd_bmp, LOGO16_GLCD_WIDTH, LOGO16_GLCD_HEIGHT, BLACK);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > ptrLcd->height()) {
        icons[f][XPOS] = rand() % ptrLcd->width();
        icons[f][YPOS] = 0;
        icons[f][DELTAY] = (rand() % 20) + 1;
      }
    }
   }
}


void Test::testdrawchar(void)
{
  ptrLcd->setTextSize(1);
  ptrLcd->setTextColor(WHITE);
  ptrLcd->setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    ptrLcd->write(i);
    if ((i > 0) && (i % 21 == 0))
      ptrLcd->println();
  }
  ptrLcd->display();
  HAL_Delay(1);
}

void Test::testdrawcircle(void) {
  for (int16_t i=0; i<ptrLcd->height(); i+=2) {
    ptrLcd->drawCircle(ptrLcd->width()/2, ptrLcd->height()/2, i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
}

void Test::testfillrect(void) {
  uint8_t color = 1;
  for (int16_t i=0; i<ptrLcd->height()/2; i+=3) {
    // alternate colors
    ptrLcd->fillRect(i, i, ptrLcd->width()-i*2, ptrLcd->height()-i*2, color%2);
    ptrLcd->display();
    HAL_Delay(1);
    color++;
  }
}

void Test::testdrawtriangle(void) {
  for (int16_t i=0; i<std::min(ptrLcd->width(),ptrLcd->height())/2; i+=5) {
    ptrLcd->drawTriangle(ptrLcd->width()/2, ptrLcd->height()/2-i,
                     ptrLcd->width()/2-i, ptrLcd->height()/2+i,
                     ptrLcd->width()/2+i, ptrLcd->height()/2+i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
}

void Test::testfilltriangle(void) {
  uint8_t color = WHITE;
  for (int16_t i=std::min(ptrLcd->width(),ptrLcd->height())/2; i>0; i-=5) {
    ptrLcd->fillTriangle(ptrLcd->width()/2, ptrLcd->height()/2-i,
                     ptrLcd->width()/2-i, ptrLcd->height()/2+i,
                     ptrLcd->width()/2+i, ptrLcd->height()/2+i, WHITE);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    ptrLcd->display();
    HAL_Delay(1);
  }
}

void Test::testdrawroundrect(void) {
  for (int16_t i=0; i<ptrLcd->height()/2-2; i+=2) {
    ptrLcd->drawRoundRect(i, i, ptrLcd->width()-2*i, ptrLcd->height()-2*i, ptrLcd->height()/4, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
}

void Test::testfillroundrect(void) {
  uint8_t color = WHITE;
  for (int16_t i=0; i<ptrLcd->height()/2-2; i+=2) {
    ptrLcd->fillRoundRect(i, i, ptrLcd->width()-2*i, ptrLcd->height()-2*i, ptrLcd->height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    ptrLcd->display();
    HAL_Delay(1);
  }
}

void Test::testdrawrect(void) {
  for (int16_t i=0; i<ptrLcd->height()/2; i+=2) {
    ptrLcd->drawRect(i, i, ptrLcd->width()-2*i, ptrLcd->height()-2*i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
}

void Test::testdrawline() {
  for (int16_t i=0; i<ptrLcd->width(); i+=4) {
    ptrLcd->drawLine(0, 0, i, ptrLcd->height()-1, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  for (int16_t i=0; i<ptrLcd->height(); i+=4) {
    ptrLcd->drawLine(0, 0, ptrLcd->width()-1, i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  HAL_Delay(250);

  ptrLcd->clearDisplay();
  for (int16_t i=0; i<ptrLcd->width(); i+=4) {
    ptrLcd->drawLine(0, ptrLcd->height()-1, i, 0, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  for (int16_t i=ptrLcd->height()-1; i>=0; i-=4) {
    ptrLcd->drawLine(0, ptrLcd->height()-1, ptrLcd->width()-1, i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  HAL_Delay(250);

  ptrLcd->clearDisplay();
  for (int16_t i=ptrLcd->width()-1; i>=0; i-=4) {
    ptrLcd->drawLine(ptrLcd->width()-1, ptrLcd->height()-1, i, 0, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  for (int16_t i=ptrLcd->height()-1; i>=0; i-=4) {
    ptrLcd->drawLine(ptrLcd->width()-1, ptrLcd->height()-1, 0, i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  HAL_Delay(250);

  ptrLcd->clearDisplay();
  for (int16_t i=0; i<ptrLcd->height(); i+=4) {
    ptrLcd->drawLine(ptrLcd->width()-1, 0, 0, i, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  for (int16_t i=0; i<ptrLcd->width(); i+=4) {
    ptrLcd->drawLine(ptrLcd->width()-1, 0, i, ptrLcd->height()-1, WHITE);
    ptrLcd->display();
    HAL_Delay(1);
  }
  HAL_Delay(250);
}

void Test::testscrolltext(void) {
  ptrLcd->setTextSize(2);
  ptrLcd->setTextColor(WHITE);
  ptrLcd->setCursor(10,0);
  ptrLcd->clearDisplay();
  ptrLcd->println("scroll");
  ptrLcd->display();
  HAL_Delay(1);

  ptrLcd->startscrollright(0x00, 0x0F);
  HAL_Delay(2000);
  ptrLcd->stopscroll();
  HAL_Delay(1000);
  ptrLcd->startscrollleft(0x00, 0x0F);
  HAL_Delay(2000);
  ptrLcd->stopscroll();
  HAL_Delay(1000);
  ptrLcd->startscrolldiagright(0x00, 0x07);
  HAL_Delay(2000);
  ptrLcd->startscrolldiagleft(0x00, 0x07);
  HAL_Delay(2000);
  ptrLcd->stopscroll();
}


