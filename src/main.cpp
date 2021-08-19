#include <Arduino.h>

#include "hwconfig.h"
#include "Config.h"

#include "Hardware.h"
#include "MainController.h"
#include "controllers/TestController.h"

TestController testController = TestController();

MainController mainController = MainController();

void setup() {
    Serial.begin(SERIAL_BAUD);
    delay(100);
    Serial.println();
    Serial.println("===============================");
    Serial.println("*     Pigatron Industries     *");
    Serial.println("===============================");
    Serial.println();

    Hardware::hw.init();
    mainController.registerController(testController);
    mainController.init();
}

void loop() {
    mainController.process();
}
