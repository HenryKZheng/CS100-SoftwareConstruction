#ifndef __SUB_HPP__
#define __SUB_HPP__


#include "base.hpp"
#include <string>


class Sub : public Base {
   private:
        double value;
        Base* op;
        Base* mult;

   public:
        Sub(Base* op, Base* mult) {
		 this->op = op;
		 this->mult = mult; 
	}

        double evaluate() { return op->evaluate() - mult->evaluate();}
        string stringify() { return op->stringify() +  " - " + mult->stringify(); }
};


#endif

