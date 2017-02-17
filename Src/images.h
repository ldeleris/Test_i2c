/*
 * images.h
 *
 *  Created on: 16 f�vr. 2017
 *      Author: Laurent
 */

#ifndef IMAGES_H_
#define IMAGES_H_

#define me_width 64
#define me_height 64

static const unsigned char me_bits[] = {
   0x00, 0x80, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff,
   0x3f, 0xff, 0x01, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00,
   0x00, 0xf0, 0xff, 0xff, 0xff, 0xfb, 0x07, 0x00, 0x00, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x07, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00,
   0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0xf8, 0xe7, 0xff,
   0xff, 0xff, 0x07, 0x00, 0x00, 0xf8, 0xb7, 0xf3, 0xff, 0xff, 0x07, 0x00,
   0x00, 0xf8, 0x63, 0x02, 0xec, 0xff, 0x07, 0x00, 0x00, 0xf0, 0x61, 0x00,
   0xc8, 0xff, 0x07, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x80, 0xff, 0x07, 0x00,
   0x00, 0xe0, 0x01, 0x00, 0xa0, 0xff, 0x07, 0x00, 0x00, 0xe0, 0x01, 0x00,
   0x00, 0xfe, 0x07, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00, 0x00, 0xf0, 0x01, 0x00,
   0x00, 0xe8, 0x03, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0xe0, 0x03, 0x00,
   0x00, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0x07, 0x00, 0x00, 0xf8, 0x01, 0x00,
   0x80, 0xe4, 0x07, 0x00, 0x00, 0xf8, 0x0c, 0x00, 0x70, 0xf1, 0x0f, 0x00,
   0x00, 0xf8, 0xf3, 0x07, 0x3e, 0xe0, 0x1f, 0x00, 0x00, 0xf8, 0xc5, 0x07,
   0xfe, 0xe3, 0x0f, 0x00, 0x00, 0xe0, 0xc1, 0x0f, 0xbc, 0xe0, 0x07, 0x00,
   0x00, 0xe0, 0x91, 0x00, 0xcc, 0xe4, 0x07, 0x00, 0x00, 0xe0, 0x09, 0x00,
   0x02, 0xe0, 0x07, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x48, 0xe0, 0x07, 0x00,
   0x00, 0x80, 0x01, 0x00, 0x00, 0x60, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
   0x00, 0xb0, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00,
   0x00, 0x80, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00,
   0x00, 0x60, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00,
   0x00, 0xe0, 0x01, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x08,
   0x00, 0x70, 0x00, 0x00, 0x00, 0xe0, 0x07, 0x40, 0x00, 0xf8, 0x00, 0x00,
   0x00, 0xe0, 0x03, 0x90, 0x00, 0xf8, 0x01, 0x00, 0x00, 0xf8, 0x07, 0x00,
   0x00, 0xf8, 0x01, 0x00, 0x00, 0xf8, 0x07, 0xcf, 0x04, 0xf8, 0x01, 0x00,
   0x00, 0xfc, 0x17, 0x50, 0x0b, 0xf8, 0x03, 0x00, 0x00, 0xfc, 0x2f, 0x80,
   0x00, 0x7e, 0x07, 0x00, 0x00, 0xfe, 0x0f, 0xd0, 0x00, 0x76, 0x1b, 0x00,
   0x00, 0xfe, 0x5f, 0x00, 0x00, 0xf6, 0x0e, 0x00, 0x80, 0xff, 0xdf, 0x00,
   0x40, 0x76, 0x77, 0x00, 0x80, 0xfb, 0x5f, 0x00, 0xa0, 0xf7, 0xfb, 0x00,
   0xc0, 0xff, 0x3b, 0x00, 0xe8, 0xf3, 0xdc, 0x01, 0xe0, 0xfd, 0xff, 0x53,
   0xf0, 0xf3, 0x73, 0x01, 0xe0, 0xbb, 0xff, 0xcf, 0xfc, 0xf3, 0xf3, 0x07,
   0xf0, 0xff, 0x79, 0x2f, 0xff, 0x79, 0x4f, 0x0b, 0xd8, 0xbf, 0xf9, 0xff,
   0xff, 0xf9, 0xb6, 0x0a, 0xf8, 0xfb, 0xfb, 0xff, 0xff, 0xf8, 0xb3, 0x3c,
   0xfc, 0xfa, 0xf3, 0xff, 0xff, 0xf8, 0x3a, 0x2b, 0xfe, 0xff, 0xe1, 0xff,
   0xff, 0xfd, 0xef, 0x0c, 0xff, 0xaf, 0xf3, 0xff, 0xff, 0xfe, 0x33, 0x15,
   0xf6, 0xfe, 0xfb, 0xff, 0x7f, 0xff, 0x2a, 0x03, 0x5e, 0xff, 0xfb, 0xff,
   0x3f, 0xff, 0x21, 0x01, 0xff, 0xff, 0xef, 0xff, 0x1f, 0x7f, 0x08, 0x00,
   0xdc, 0xfc, 0xdf, 0xff, 0x3f, 0x5e, 0x00, 0x00, 0xb0, 0xff, 0x9f, 0xff,
   0x5f, 0x1e, 0x00, 0x00, 0x00, 0xef, 0xff, 0xfc, 0x47, 0x1e, 0x00, 0x00,
   0x20, 0xa0, 0xd7, 0xf0, 0x87, 0x17, 0x00, 0x00, 0x00, 0x90, 0x87, 0xe0,
   0x03, 0x07, 0x00, 0x00, 0x00, 0x20, 0x23, 0xc0, 0x83, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x26, 0x81, 0x81, 0x07, 0x00, 0x00 };



#endif /* IMAGES_H_ */
