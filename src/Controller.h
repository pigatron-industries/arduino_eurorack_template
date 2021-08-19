#ifndef Controller_h
#define Controller_h

class Controller {
    public:
        virtual void init() {}
        virtual void update() {}
        virtual void process() = 0;
};

#endif
