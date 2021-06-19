#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
using namespace std; 


class Op : public Base {
    private:
	double value;

    public:
        Op(double value) : Base() {this->value = value;}
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return to_string(value); }
};

#endif //__OP_HPP__
