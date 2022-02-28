#include <led.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <board_state.h>
#include <connection_manager.h>
#include <temperature.h>

Temperature temperature;
BoardState state(WiFi, temperature);
LEDScreen led;
ConnectionManager connectionManager;

void setup()
{
  Serial.begin(9600);

  led.start();
  connectionManager.setup();
  connectionManager.connect([]()
                            { led.printCurrentState(state); });
}

void loop()
{
  led.printCurrentState(state);
  delay(500);
}
