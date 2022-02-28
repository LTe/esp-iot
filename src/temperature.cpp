
#include <temperature.h>
#include <Arduino.h>

Temperature::Temperature()
{
    wire = OneWire(D3);
    setup();
}

void Temperature::setup(void)
{
    wire.search(address);
}

float Temperature::read(void)
{
    byte data[9];

    wire.reset();
    wire.select(address);
    wire.write(TEMPERATURE_CONVERSION_COMMAND);

    delay(1000);

    wire.reset();
    wire.select(address);
    wire.write(SCRATCHPAD_MEMORY_READ_COMMAND);
    wire.read_bytes(data, 9);

    return convert(data);
}

float Temperature::convert(byte data[])
{
    float celsius;
    int16_t raw = (data[1] << 8) | data[0];

    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00)
        raw = raw & ~7; // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20)
        raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40)
        raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
    celsius = (float)raw / 16.0;

    return celsius;
}
