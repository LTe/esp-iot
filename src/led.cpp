#include <led.h>
#include <board_state.h>

LEDScreen::LEDScreen()
{
    display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
}

void LEDScreen::printCurrentState(BoardState state)
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(String("Temp " + String(state.getCurrentTemperature(), 1) + "*C"));
    display.setTextSize(1);
    display.println(String("WiFi " + state.getCurrentSSID()));

    display.display();
    delay(2000);
}

void LEDScreen::start()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }

    display.display();
    delay(1000);

    display.clearDisplay();
}
