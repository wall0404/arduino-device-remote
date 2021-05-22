#include "Device.h" 
#include "Observer.h"

class Taster : public Observer {
  private:
    int _LEDPin;
    int _TasterPin;
    boolean _state;
    Device *_device;
    boolean _stateBeforeDeviceTurnedOff;

    //Call the right metod desired by the mode of this taster
    void handleClick() {
      if(_mode == 1 && _state == false) {
        _device->turnOn();
        updateState();
      }
      else if(_mode == 1 && _state == true) {
        _device->turnOff();
        updateState();
      }
      _device->notifyObservers(_mode, state);
    }


  public:
    // constructor
    Taster(int LEDPin, int TasterPin, int mode, Device *device) {
      _LEDPin = LEDPin;
      _TasterPin = TasterPin;
      _state = false;
      _mode = mode;
      _device = device;
      _stateBeforeDeviceTurnedOff = false;

      init();
    }
    void init() {
      pinMode(_LEDPin, OUTPUT);
      pinMode(_TasterPin, INPUT);

      _device->attachObserver(*this);
    }
    
    //Check if the taster is pressed. if so, handle the click
    void checkIfPressed() {
      if (digitalRead(_TasterPin) == HIGH) {
        delay(50);
        while(digitalRead(_TasterPin) == HIGH) {
          //Wait until taster is released
        }
        this->handleClick();
        delay(50);
      }
    }
    //If the button was pressed on an other device e.g. Projector was turned on by remote : switch the variable state and turn the led on
    void updateState() {
      //switch state and led on/off
      if(_state) {
        digitalWrite(_LEDPin, LOW);
      }
      else {
        digitalWrite(_LEDPin, HIGH);
      }

      _state = !_state;
    }

    
    /**
     * is called when a taster of the same device was pressed
     *
     * @param mode Mode of the taster that was pressed
     */
    void updateObserver(int mode, int state) {
      //check if it was this taster that was pressed. if yes nothing happens
      if(mode != _mode) {
        //TODO

        //if on/off was turned off then turn this led button off and save last state

        //if on/off was turned on then turn this led button on if last state was also on
      }
    }
};
