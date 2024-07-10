/*
  SingleSevenSegment.cpp - Display digits on a single 7 segment display.
  Created by Darren B, 2024.
  https://github.com/drrnb/SingleSevenSegment
*/
#include <SingleSevenSegment.h>

// Counter with Delay
SingleSevenSegment display;

byte segmentPins[8] = {D0, D1, D2, D3, D4, D5, D6, D7}; // a-g segments
byte digitPin = D8;

void setup() {
  display.init(COMMON_ANODE, digitPin, segmentPins);
  display.blank();
}

void loop() {
  for (int i = 0; i < 10; i++) {
    display.showDigit(i, i%2 == 0);
    delay(1000);
  }
}
