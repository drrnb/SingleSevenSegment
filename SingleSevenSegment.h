#ifndef SingleSevenSegment_h
#define SingleSevenSegment_h
#include "Arduino.h"

#define COMMON_ANODE 1
#define COMMON_CATHODE 0

class SingleSevenSegment{
  public:
    SingleSevenSegment();
    void init(byte digitPinType, byte digitPin, byte segmentPins[8]);
    void blank();
    void enableOutput();
    void disableOutput();
    void showDigit(int digit, bool showPeriod = false);
    void enablePeriod();
    void disablePeriod();
    void enableSegments(byte segments[7]);
  private:
    byte digitPin;
    byte segmentPins[8];
    byte digitPinType = COMMON_CATHODE;
};

#endif
