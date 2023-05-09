#ifndef SolarPanel_logFile_h
#define SolarPanel_logFile_h

#include "Arduino.h"
#include "sd.h"
#include <SPI.h>
#include <SD.h>

class SolarPanel_logFile {
  public:
  String buffer;
  void save();
  void write2log(String str);

  private:
  File lf;
  int ok = 1;
};

#endif
