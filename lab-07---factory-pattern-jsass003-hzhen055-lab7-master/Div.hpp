#ifndef DIV_HPP
#define DIV_HPP

#include "base.hpp"
#include <string>
#include "op.hpp"

using namespace std;
 
class Div: public Base{
        private:
                double value;
		Base* x;
		Base* y; 
        public:
                Div(Base* x, Base* y) : Base() {
			this->x = x; 
			this->y = y; 
			this->value = x->evaluate() / y->evaluate(); 
		}
                virtual double evaluate() { return value; }
                virtual std::string stringify() {
			string temp = ""; 
			temp += x->stringify()  + "/" + y->stringify();
			return temp;
		 }

};
#endif
