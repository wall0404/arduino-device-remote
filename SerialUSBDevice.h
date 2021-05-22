#include "Arduino.h"
#include "Device.h" 


class SerialUSBDevice : public Device
{
  public:
  
    //constructor
    SerialUSBDevice() {
      init();
    }

    //setup connection
    void init() {
       //TODO
    }

    virtual void turnOn() {
      //TODO
    }
    virtual void turnOff() {}
    virtual void selectSource(int source) {}
};
