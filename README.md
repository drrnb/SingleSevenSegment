# SingleSevenSegment
An Arduino library for displaying numbers and segments of a singular seven segment display.

# Why?
Most libraries out there cater for multiple displays such as those in clocks, ovens etc... but sometimes, that's overkill and just 1 is enough.

# How?
See the examples directory for an example bit to display a number 8 for example is as simple as setting the corresponding pins and:  
```cpp
#include <SingleSevenSegment.h>

SingleSevenSegment display;

byte segmentPins[8] = {D0, D1, D2, D3, D4, D5, D6, D7}; // a-g segments
byte digitPin = D8;

void setup() {
  display.init(COMMON_ANODE, digitPin, segmentPins);
  //display.blank();
  display.showDigit(8);
}

void loop() {}
```
