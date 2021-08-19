#ifndef MainController_h
#define MainController_h

#include <Bounce2.h>
#include <inttypes.h>
#include "Controller.h"

#define MAX_CONTROLLERS 8

class MainController {

public:
    MainController();
    void init();
    void process();

    void registerController(Controller& controller);

private:

    int activeController = 0;
    int controllerSize = 0;
    Controller* controllers[MAX_CONTROLLERS];

    void setActiveController(int controllerIndex);


};

#endif
