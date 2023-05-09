#ifndef SolarPanel_panel_h
#define SolarPanel_panel_h

#include "Servo.h"
#include "Arduino.h"

typedef struct panelMonitorOut_t {
  int status;
  float voltage;
} panelMonitorOut;
  
typedef struct {
    int _panel = 0;
    int monitorPin;

    int horizontalServoPin;
    int verticalServoPin;
    
    Servo horizontalServo;
    Servo verticalServo;

    int positionBuffer[2];
    float voltageBuffer;

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
      
      float voltage = analogRead(this->monitorPin) * (5.0 / 1023.0);
      b.voltage = voltage;

      int s = voltage != 0.00;
      b.status = s;

      return b;
    }
} panel_t;

class SolarPanel_panel {
  public:
    int attachPanel(panel_t panel);
    //void disattachPanel();
    float getTotalVoltage();
    int cnt;
    panel_t* panelsArray = {};
  //private:
    
};

#endif
