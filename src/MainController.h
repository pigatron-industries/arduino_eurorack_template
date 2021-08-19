#ifndef MainController_h
#define MainController_h

#include <Eurorack.h>
#include "Controller.h"

#define MAX_CONTROLLERS 8

class MainController {

public:
    MainController();
    void init();
    void process();

    void registerController(Controller& controller);

private:
    ControllerList<Controller, 8> controllers;

};

#endif
