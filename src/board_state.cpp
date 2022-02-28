#include <board_state.h>
#include <temperature.h>

BoardState::BoardState(ESP8266WiFiClass &wifi, Temperature &temperature)
{
  wifi = wifi;
  temperature = temperature;

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
