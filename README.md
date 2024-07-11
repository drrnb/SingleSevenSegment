# SingleSevenSegment
An Arduino library for displaying numbers and segments of a singular seven segment display.

# Why?
Most libraries out there cater for multiple displays such as those in clocks, ovens etc... but sometimes, that's overkill and just 1 is enough.

# How?
See [the counter example project file](examples/counterWithDelay/counterWithDelay.ino), but to display a number 8 for example is as simple as setting the corresponding pins and:  
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
# License
```
SingleSevenSegment Arduino Library
Copyright (C) 2024  Darren B <github.com/drrnb>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
[See LICENSE file](LICENSE) for the full shmack.
