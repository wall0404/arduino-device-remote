#include <BridgeHttpClient.h>
#include <Bridge.h>
#include "Arduino.h"
#include "Device.h" 


class NetworkDevice : public Device
{
  protected:
    String _ip;
    
    BridgeHttpClient client;
    
  public:
    NetworkDevice(const char *ip) {
      _ip = ip;
    }

    virtual void sendPostCommand(const char *url, const char *data) {
      
      Bridge.begin();
      client.post(url, data);
    }
    virtual void addHeaderToRequest(const char *header) {
      client.addHeader(header);
    }
    virtual void setBasicAuth(const char *username, const char *password) {
      client.basicAuth(username, password);
    }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void selectSource(int source) = 0;
};
