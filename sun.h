#ifndef SolarPanel_sun_h
#define SolarPanel_sun_h

#include "Arduino.h"
#include "panel.h"

typedef struct sunLocation_t {
  int x;
  int y;
} sunLocation_t;

class SolarPanel_sun {
  public:
    sunLocation_t findSun(panel_t targetPanel);
    sunLocation_t* findAll();
    void trace(panel_t targetPanel);
    void traceAll();
  //private:
};

#endif
