#include "Quad7Segment.h"

void Quad7Segment::setNumber(int n){
	display_digits[0] = nums[n % 10];
	display_digits[1] = nums[n / 10 % 10];
	display_digits[2] = nums[n / 100 % 10];
	display_digits[3] = nums[n / 1000 % 10];
}

void Quad7Segment::update(){
	unsigned short display_bit;
	for (int i=0;i<8;i++)
	{
		display_bit = 0b1111 & ~((((display_digits[0] >> i) & 1) << 0) |
		(((display_digits[1] >> i) & 1) << 1) |
		(((display_digits[2] >> i) & 1) << 2) |
		(((display_digits[3] >> i) & 1) << 3));
		shreg.pushn(0b10000 << i | display_bit, 12);
		shreg.latch();
	}
}
