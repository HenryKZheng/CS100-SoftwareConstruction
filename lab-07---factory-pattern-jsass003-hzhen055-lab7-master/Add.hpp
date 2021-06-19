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
        string stringify() { return op->stringify() +  " + " + mult->stringify(); }
};



#endif
