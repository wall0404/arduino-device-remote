#include "Arduino.h"
#include "Device.h" 
#include <SoftwareSerial.h>


class RS232Device : public Device
{
  protected:
    int _pinTX;
    int _pinRX;
    SoftwareSerial *serialCon;
    
  public:
    RS232Device(int pinTX, int pinRX, int baudRate) {
      _pinTX = pinTX;
      _pinRX = pinRX;

      serialCon = new SoftwareSerial(_pinTX, _pinRX);
      serialCon->begin(baudRate);
    }

    virtual void sendcommand(String command) {
      serialCon->println(command);
    }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void selectSource(int source) = 0;
};
