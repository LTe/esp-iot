#ifndef _BOARD_STATE_H_
#define _BOARD_STATE_H_

#include <ESP8266WiFi.h>
#include <temperature.h>

class BoardState
{
    Temperature temperature;
    ESP8266WiFiClass wifi;

public:
    BoardState(ESP8266WiFiClass wifi);
    String getCurrentSSID();
    float getCurrentTemperature();
};

#endif
