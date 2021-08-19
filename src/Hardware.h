#ifndef Hardware_h
#define Hardware_h

#include <Arduino.h>
#include <eurorack.h>
#include <eurorack_mcp23s17.h>
#include <Adafruit_SSD1306.h>
#include "hwconfig.h"


class Hardware {
    public:
        static Hardware hw;
        void init();

        // Direct connections
        RotaryEncoder encoder = RotaryEncoder(ENCODER_PIN1, ENCODER_PIN2);
        PushButton<> encoderButton = PushButton<>(DigitalInputPin(ENCODER_BTN_PIN));

        // IO Expander
        gpio_MCP23S17 mcp23s17 = gpio_MCP23S17(GPIO_CS_PIN, GPIO_ADDRESS);
        MCP23S17OutputPin mcp23s17outputPins[2] = {
            MCP23S17OutputPin(mcp23s17, 0),
            MCP23S17OutputPin(mcp23s17, 1)
        };
        MCP23S17InputPin mcp23s17inputPins[1] = {
            MCP23S17InputPin(mcp23s17, 2)
        };

        PushButton<MCP23S17InputPin> pushButton = PushButton<MCP23S17InputPin>(mcp23s17inputPins[0]);

        // OLED Display
        Adafruit_SSD1306 display = Adafruit_SSD1306(64, 32);
};

#endif