#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include <OneWire.h>

#define TEMPERATURE_CONVERSION_COMMAND 0x44
#define SCRATCHPAD_MEMORY_READ_COMMAND 0XBE

class Temperature
{
    OneWire wire;
    byte address[8];

public:
    Temperature();
    void setup(void);
    float read(void);
    float convert(uint8_t *data);
};

#endif
