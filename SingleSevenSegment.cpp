#include "SingleSevenSegment.h"
#include <Arduino.h>

SingleSevenSegment::SingleSevenSegment(){}

void SingleSevenSegment::init(byte digitPinType, byte digitPin, byte segmentPins[8]){
  this->digitPin = digitPin;
  this->digitPinType = digitPinType;

  pinMode(digitPin, OUTPUT);

  for (int i = 0; i < 8; i++) {
    this->segmentPins[i] = segmentPins[i];
    pinMode(segmentPins[i], OUTPUT);
  }

  enableOutput();
  blank();
}

void SingleSevenSegment::blank(){
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], digitPinType);
  }
}

void SingleSevenSegment::enableOutput(){
  digitalWrite(digitPin, digitPinType);
}

void SingleSevenSegment::disableOutput(){
  digitalWrite(digitPin, !digitPinType);
}

void SingleSevenSegment::enableSegments(byte segments[7]){
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], segments[i] == 1 ? !digitPinType : digitPinType);
  }
}

void SingleSevenSegment::showDigit(int digit, bool showPeriod){
  showPeriod ? enablePeriod() : disablePeriod();

  byte segmentsToEnable[7];
  const bool digitSegments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };

  if (digit >= 0 && digit <= 9){
    for (int i = 0; i < 7; ++i) {
      segmentsToEnable[i] = digitSegments[digit][i];
    }
  }
  enableSegments(segmentsToEnable);
}

void SingleSevenSegment::enablePeriod(){
  digitalWrite(segmentPins[7], !digitPinType);
}

void SingleSevenSegment::disablePeriod(){
  digitalWrite(segmentPins[7], digitPinType);
}
