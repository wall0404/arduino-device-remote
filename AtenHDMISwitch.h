#include "Arduino.h"
#include "RS232Device.h" 


class AtenHDMISwitch : public RS232Device
{  
  public:
  
    
  
    //constructor
    AtenHDMISwitch(int pinTX, int pinRX) : RS232Device(pinTX, pinRX, 19200) {
      //calls base constructor
    }

    virtual void turnOn() {}
    virtual void turnOff() {}
    virtual void selectSource(int source) {
      sendcommand("sw i0"+String(source));  
    }

};
