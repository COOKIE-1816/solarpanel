#include "Arduino.h"
#include "panel.h"
#include "logfile.h"
#include <Servo.h>

SolarPanel_logFile sp_lf2;

/*typedef struct {
    int _panel = 0;
    int monitorPin;

    int horizontalServoPin;
    int verticalServoPin;
    
    Servo horizontalServo;
    Servo verticalServo;

    int positionBuffer[2];

    void init() {
      this->horizontalServo.attach(this->horizontalServoPin);
      this->verticalServo.attach(  this->verticalServoPin);

      this->moveTo(0, 0);
    }

    void moveTo(int angleX, int angleY) {
      this->positionBuffer[0] = angleX;
      this->positionBuffer[1] = angleY;
      
      this->horizontalServo.write(angleX);
      this->verticalServo.write(angleY);
    }
    
    
    panelMonitorOut_t check() {
      panelMonitorOut_t b;
      
      int voltage = analogRead(this->monitorPin) * (5.0 / 1023.0);
      b.voltage = voltage;

      int s = voltage != 0;
      b.status = s;

      return b;
    }
} panel_t;*/

int SolarPanel_panel::attachPanel(panel_t panel) {
  for(int i = 0; 0 < 15; i++) {
    if(panelsArray[i]._panel == 0) {
      cnt++;
      
      panel._panel = 1;
      panelsArray[i] = panel;
      
      return i;
    }
  }

  sp_lf2.write2log("Error: Failed to attach another panel (16). Not enough empty slots.");
  return (-1);
}
