#include <board_state.h>

BoardState::BoardState(ESP8266WiFiClass wifi, float temperature)
{
  wifi = wifi;
  temperature = temperature;
};

String BoardState::getCurrentSSID()
{
  if (wifi.getMode() == WiFiMode::WIFI_AP)
  {
    return wifi.softAPSSID();
  }
  else
  {
    return wifi.SSID();
  }
}

float BoardState::getCurrentTemperature()
{
  return temperature;
}
