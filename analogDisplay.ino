#include "Quad7Segment.h"

Quad7Segment qs(2, 3, 4, 5);

int start, end;

void setup() {
	start = millis();
	qs.setNumber(analogRead(A0));
}

void loop() {
	end = millis();
	if (end - start > 100 ) {
		qs.setNumber(analogRead(A0));
		start = end;
	}
	qs.update();
}
