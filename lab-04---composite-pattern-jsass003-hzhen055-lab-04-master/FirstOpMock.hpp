#ifndef __FIRST_OP_MOCK__
#define __FIRST_OP_MOCK__

#include <iostream>
#include "base.hpp"


class FirstOpMock : public Base {
    public:
        FirstOpMock(double value) : Base() { }
        virtual double evaluate() { return -1; }
        virtual string stringify() { return "-1"; }
};

#endif 
