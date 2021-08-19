#ifndef OctaSource_h
#define OctaSource_h

#include <inttypes.h>
#include "../Controller.h"

class TestController : public Controller {

public:
    TestController();
    virtual void init();
    virtual void process();
    
private:

};

#endif
