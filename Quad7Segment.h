#ifndef QUAD7SEGMENT_H
#define QUAD7SEGMENT_H
#include "HC595.h"
class Quad7Segment {
  public:
    Quad7Segment(int ser, int srClk, int rClk, int srClr):
		shreg(2, 3, 4, 5){}
    void setup();
    void update();
	void setNumber(int n);
  private:
	HC595 shreg;
	unsigned short display_digits[4] = {0, 0, 0, 0};
	unsigned short nums[10] = {
		0b11010111,
		0b00010100, 
		0b11001101, 
		0b01011101,
		0b00011110,
		0b01011011,
		0b11011011,
		0b00010101,
		0b11011111,
		0b00011111
	};
};
#endif
