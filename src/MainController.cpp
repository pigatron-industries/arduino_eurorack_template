#include "MainController.h"
#include "hwconfig.h"
#include "Config.h"
#include "Hardware.h"

#include <Arduino.h>
#include <math.h>


MainController::MainController() {
}

void MainController::init() {
    controllers.getActiveController()->init();
}

void MainController::process() {
    Hardware::hw.encoderButton.update();
    if(Hardware::hw.encoder.update()) {
        if(Hardware::hw.encoderButton.held()) {
            //change controller when button held down
            if(Hardware::hw.encoder.getMovement() > 0) {
                controllers.incrementController();
                init();
            } else if (Hardware::hw.encoder.getMovement() < 0) {
                controllers.decrementController();
                init();
            }
        } else {
            //button pressed
        }
    }

    controllers.getActiveController()->init();
}

void MainController::registerController(Controller& controller) {
    controllers.addController(controller);
}
