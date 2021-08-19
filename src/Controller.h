#ifndef Controller_h
#define Controller_h

#include "Hardware.h"
#include <Eurorack.h>

enum UIEvent {
    EVENT_NONE,
    EVENT_CLOCKWISE,
    EVENT_COUNTERCLOCKWISE,
    EVENT_SHORT_PRESS,
    EVENT_LONG_PRESS
};

class Controller {
    public:
        virtual void init() {};
        virtual void update() {}
        virtual void event(UIEvent event, int itemIndex) {}
        virtual void process() = 0;
};

#endif
