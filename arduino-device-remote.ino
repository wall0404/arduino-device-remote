#include "Arduino.h" 
#include "Device.h" 
#include "Taster.h" 
#include "SerialUSBDevice.h" 
#include "AtenHDMISwitch.h" 
#include "PanasonicProjector.h" 
#include <Console.h>


int MODE_ONOFF = 1;
int MODE_SOURCE_1 = 2;
int MODE_SOURCE_2 = 3;
int MODE_SOURCE_3 = 4;

  

//setup devices
AtenHDMISwitch aten(7,6);
PanasonicProjector projector("192.168.0.235", "admin1", "panasonic");

//Cast specific devices into the generic class "device"
Device *projectorDevice = &projector;
Device *atenDevice = &aten;
  
//Setup taster
/*
 * Taster(int LEDPin, int TasterPin, int mode, Device *device)
 
Taster taster[] = {
  Taster(12,8,MODE_ONOFF,device)
};*/

void setup() {
  projector.turnOff();
}

void loop() {
  
  //call tests
  for (int i = 0; i < 1; i++) {
    //taster[i].checkIfPressed();
  }

}
