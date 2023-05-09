#include "Arduino.h"
#include "logfile.h"

void SolarPanel_logFile::init() {
  lf = SD.open("SOLARPANEL.TXT", FILE_WRITE);
  if(lf) {
    write2log("Ok: Log file initialization OK.");
    
    ok = 1;
    return;
  }

  Serial.println("Error: Log file failed to open. No log file will be written.");
}

void SolarPanel_logFile::write2log(String str) {
  if(ok == 1) 
    lf.print(str);
    
  Serial.print(str);
}
