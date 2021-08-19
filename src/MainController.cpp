#include "MainController.h"
#include "hwconfig.h"
#include "Config.h"
#include "Hardware.h"

#include <Arduino.h>
#include <math.h>


MainController::MainController() {
}

void MainController::init() {
    controllers[activeController]->init();
}

void MainController::process() {
    Hardware::hw.encoderButton.update();
    if(Hardware::hw.encoder.update()) {
        if(Hardware::hw.encoderButton.held()) {
            //change controller when button held down
            if(Hardware::hw.encoder.getMovement() > 0) {
                int controllerIndex = ((activeController + 1) % (controllerSize));
                setActiveController(controllerIndex);
            } else if (Hardware::hw.encoder.getMovement() < 0) {
                int controllerIndex = activeController > 0 ? activeController - 1 : controllerSize - 1;
                setActiveController(controllerIndex);
            }
        } else {
            //button pressed
        }
    }

    controllers[activeController]->process();
}

void MainController::registerController(Controller& controller) {
    controllers[controllerSize] = &controller;
    controllerSize++;
}

void MainController::setActiveController(int controllerIndex) {
    controllers[controllerIndex]->init();
    activeController = controllerIndex;
}
