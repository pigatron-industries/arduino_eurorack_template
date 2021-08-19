#include "Hardware.h"

Hardware Hardware::hw = Hardware();

void Hardware::init() {
    mcp23s17.begin();
    for(MCP23S17OutputPin& outputPin : mcp23s17outputPins) {
        outputPin.init();
    }
    for(MCP23S17InputPin& inputPin : mcp23s17inputPins) {
        inputPin.init();
    }
    pushButton.init();

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
