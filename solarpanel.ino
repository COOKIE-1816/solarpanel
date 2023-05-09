#include <Servo.h>
#include "logfile.h"
#include "sd.h"

#if !defined(ARDUINO_AVR_MEGA2560)
  #error "Arduino MEGA2560 AVR board is required."
#endif
#if F_CPU != 16000000L
  #error "Invaild CPU frequency"
#endif

SolarPanel_logFile sp_lf;
SolarPanel_SD sp_sd;

void setup() {
  Serial.begin(9600);

  sp_sd.init();

  sp_lf.write2log("\n----- RECORD START -----");
  sp_lf.write2log("\nFirmware version: v 1.0.02.00");
  sp_lf.write2log("\nCopyright (C) Vaclav Hajsman (a.k.a. COOKIE) 2023. All rights reserved.");
  sp_lf.write2log("\nhttps://github.com/COOKIE-1816/solarpanel\n\n");
}

void loop() {
  
}
