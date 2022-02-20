#ifndef _BOARD_STATE_H_
#define _BOARD_STATE_H_

#include <ESP8266WiFi.h>

class BoardState
{
    float temperature;
    ESP8266WiFiClass wifi;

public:
    BoardState(ESP8266WiFiClass wifi, float temperature = 0);
    String getCurrentSSID();
    float getCurrentTemperature();
};

#endif
