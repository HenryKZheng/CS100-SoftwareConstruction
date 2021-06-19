#ifndef __SECOND_OP_MOCK__
#define __SECOND_OP_MOCK__

#include <iostream>
#include "base.hpp"


class SecondOpMock : public Base {
    public:
        SecondOpMock(double value) : Base() { }
        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

#endif

