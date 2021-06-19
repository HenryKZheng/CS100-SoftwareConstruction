#ifndef __SEVEN_OP_MOCK__
#define __SEVEN_OP_MOCK__

#include <iostream>
#include "base.hpp"


class SevenOpMock : public Base {
    public:
        SevenOpMock(double value) : Base() { }
        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};

#endif

