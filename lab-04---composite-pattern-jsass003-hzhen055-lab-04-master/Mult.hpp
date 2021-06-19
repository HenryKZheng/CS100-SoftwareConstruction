#ifndef MULT_HPP
#define MULT_HPP

#include "base.hpp"
#include <string>
#include "op.hpp"

using namespace std;
 
class Mult: public Base{
        private:
                double value;
		Base* x; 
		Base* y;
        public:
                Mult(Base* x, Base* y){
			this->x = x; 
			this->y = y; 
			this->value = x->evaluate() * y->evaluate(); 
		}
                virtual double evaluate() { return value; }
                virtual std::string stringify() {
			string temp = ""; 
			temp += to_string(x->evaluate()) +"*"+ to_string(y->evaluate());
			return temp;  
		 }
};
#endif
