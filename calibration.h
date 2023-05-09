#ifndef SolarPanel_calibration_h
#define SolarPanel_calibration_h

#include "Arduino.h"
#include "sd.h"
#include "panel.h"
#include "logfile.h"

SolarPanel_panel p;

class SolarPanel_calibration {
  private:
  //void progress(int percentage,)
  public:
  void calibrate();
}

#endif
