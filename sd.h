#ifndef SolarPanel_SD_h
#define SolarPanel_SD_h

#include "Arduino.h"
/*#include <SPI.h>
#include <SD.h>*/

class SolarPanel_SD {
  public:
  int init();

  private:
  const int ss = 2;
  const int cs = 3;  
};

#endif
