#ifndef Device_h
#define Device_h

#include "Observer.h"

const int MAX_OBSERVERS = 10;

class Device {
  protected:
    Observer* observers[MAX_OBSERVERS];
  public:
    virtual ~Device() {}
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void selectSource(int source) = 0;
    void attachObserver(Observer &observer) {
      int i=0;
      while(true) {
        if(observers[i] == NULL) {
          observers[i] = &observer;
          break;
        }
        i++;
      }
    };
    void notifyObservers(int mode, int state) {
      for(int i = 0; i < MAX_OBSERVERS; i++) {
        if(observers[i] != NULL) {
          observers[i]->updateObserver(mode, state);
        }
      }
    };
};

#endif
