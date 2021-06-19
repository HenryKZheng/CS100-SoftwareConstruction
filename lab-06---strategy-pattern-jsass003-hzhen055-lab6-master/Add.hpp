#ifndef __ADD_HPP__
#define __ADD_HPP__


#include "base.hpp"
#include <string>

using namespace std; 


class Add : public Base {
   private:
        double value;
        Base* op;
        Base* mult;

   public:
        Add(Base* op, Base* mult){ 
		this->op= op;
		 this->mult = mult; 
	}

        double evaluate() { return op->evaluate() + mult->evaluate();}
        string stringify() { return to_string(op->evaluate()) +  " + " + to_string(mult->evaluate()); }
};



#endif
