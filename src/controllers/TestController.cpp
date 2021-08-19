#include "TestController.h"

#include "../Hardware.h"

TestController::TestController() {
}

void TestController::init() {
    Hardware::hw.mcp23s17outputPins[0].setValue(true);
    Hardware::hw.mcp23s17outputPins[1].setValue(false);
    Hardware::hw.mcp23s17.gpioPortUpdate();
}
   
void TestController::process() {
    if(Hardware::hw.pushButton.update()) {
        if(Hardware::hw.pushButton.pressed()) {
            Hardware::hw.mcp23s17outputPins[0].setValue(false);
        } else {
            Hardware::hw.mcp23s17outputPins[0].setValue(true);
        }
        Hardware::hw.mcp23s17.gpioPortUpdate();
    }
}
