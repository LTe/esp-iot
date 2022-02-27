#include <board_state.h>
#include <temperature.h>

BoardState::BoardState(ESP8266WiFiClass wifi)
{
  wifi = wifi;
  temperature = Temperature();

  temperature.setup();
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
  return temperature.read();
}
