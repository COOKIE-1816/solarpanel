#ifndef SolarPanel_logFile_h
#define SolarPanel_logFile_h

#include "Arduino.h"
#include "sd.h"
#include <SPI.h>
#include <SD.h>

class SolarPanel_logFile {
  public:
  void init();
  void write2log(String str);

  private:
  File lf;
  int ok = 0;
};

#endif
