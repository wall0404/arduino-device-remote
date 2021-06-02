#include "Arduino.h"
#include "NetworkDevice.h" 


class PanasonicProjector : public NetworkDevice
{  
  public:  
    //constructor
    PanasonicProjector(const char *ip, const char *username, const char *password) : NetworkDevice(ip) {
      setBasicAuth(username, password);
    }

    virtual void turnOn() {
      String url = "http://"+_ip+"/cgi-bin/power_on.cgi";
      
      //Define Headers
      setDefaultHeaders();
      
      String referer = "Referer: http://"+_ip+"/cgi-bin/power_ctl.cgi?key=pow_on&lang=e&from=BASIC_CTL";
      addHeaderToRequest(referer.c_str());

      //Fire Request
      sendPostCommand(url.c_str(), "lang=e");
    }
    virtual void turnOff() {
      String url = "http://"+_ip+"/cgi-bin/power_off.cgi";
      
      //Define Headers
      setDefaultHeaders();
      
      String referer = "Referer: http://"+_ip+"/cgi-bin/power_ctl.cgi?key=pow_off&lang=e&from=BASIC_CTL";
      addHeaderToRequest(referer.c_str());

      //Fire Request
      sendPostCommand(url.c_str(), "lang=e");
    }
    
    virtual void selectSource(int source) {
      
    }

    void setDefaultHeaders() {
      String host = "Host: "+_ip;
      String origin = "Origin: http://"+_ip;

      addHeaderToRequest("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3");
      addHeaderToRequest("Accept-Encoding: gzip, deflate");
      addHeaderToRequest("Accept-Language: de-DE,de;q=0.9,ru-RU;q=0.8,ru;q=0.7,en-US;q=0.6,en;q=0.5");
      addHeaderToRequest("Cache-Control: max-age=0");
      addHeaderToRequest("Connection: keep-alive");
      addHeaderToRequest("Content-Length: 6");
      addHeaderToRequest("Content-Type: application/x-www-form-urlencoded");
      addHeaderToRequest(host.c_str());
      addHeaderToRequest(origin.c_str());
      addHeaderToRequest("Upgrade-Insecure-Requests: 1");
    }

};
