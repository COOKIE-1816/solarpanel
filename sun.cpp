#include "Arduino.h"
#include "sun.h"
#include "panel.h"

SolarPanel_panel sp_p2;

sunLocation_t SolarPanel_sun::findSun(panel_t targetPanel) {
  sunLocation_t sunLocation;
  
  int maxX, maxY = 0;
  float mv = 0.00;
  int pb[2];
  
  pb[0]= targetPanel.positionBuffer[0];
  pb[1]= targetPanel.positionBuffer[1];

  //targetPanel.moveTo(0, 0);

  for(int ix = 0; ix < 180; ix = ix + 1) {
    targetPanel.moveTo(ix, 23);
    
    if(targetPanel.check().voltage > mv) {
      maxX = ix;
    }
  }

  for(int iy = 0; iy < 180; iy = iy + 1) {
    targetPanel.moveTo(maxX, iy);

    if(targetPanel.check().voltage > mv) {
      maxY = iy;
    }
  }

  sunLocation.x = maxX;
  sunLocation.y = maxY;

  return sunLocation;
}

sunLocation_t* SolarPanel_sun::findAll() {
  sunLocation_t* sunLocations;

  for(int index; index < sp_p2.cnt; index++) {
    sunLocations[index] = findSun(sp_p2.panelsArray[index]);
  }
}

void SolarPanel_sun::trace(panel_t targetPanel) {
  if(targetPanel.check().voltage < targetPanel.voltageBuffer) {
    // Voltage decreased.

    sunLocation_t sl = findSun(targetPanel);
    targetPanel.moveTo(sl.x, sl.y);
  }
}

void SolarPanel_sun::traceAll() {
  for(int index; index < sp_p2.cnt; index++) {
    trace(sp_p2.panelsArray[index]);
  }
}
