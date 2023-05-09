#include "Arduino.h"
#include "logfile.h"

void SolarPanel_logFile::save() {
  lf = SD.open("SOLARPANEL.TXT", FILE_WRITE);
  if(lf) {
    ok = 1;
    
    lf.print("\n");
    lf.print(buffer);
    
    Serial.println("Log buffer saved.");
    return;
  }

  Serial.println("Error: Log file failed to open. No log file will be written.");
  ok = 0;
}

void SolarPanel_logFile::write2log(String str) {
  if(ok == 1) 
    buffer = buffer + str;
    
  Serial.print(str);
}
