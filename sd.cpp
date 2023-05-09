#include "Arduino.h"
#include "sd.h"
#include <SPI.h>
#include <SD.h>

int SolarPanel_SD::init() {
  pinMode(ss, OUTPUT);
  
  if(!SD.begin(cs)) {
    Serial.println("Error: SD Card initialization failed. No log file will be written.");
    return 1;
  }

  Serial.println("Ok: SD Card initialization OK.");
  return 0;
}
