#ifndef __POW_HPP__
#define __POW_HPP__


#include <string>
#include "base.hpp"


class Pow : public Base {
   private:
        double value;
        Base* op;
        Base* mult;
	int sum =1;


   public:
        Pow(Base* op, Base* mult){
		 this->op = op;
		 this->mult = mult;
		 for(int i = 0; i <= mult->evaluate(); ++i){
			
		 }
				 
	}
        double evaluate() {
		if(mult->evaluate() == 0)
			return 1;
		for(int i =0; i <  mult->evaluate(); ++i){
			sum *= op->evaluate();	
		}
		value = sum;
		 return value;
	}
        string stringify() { return to_string(op->evaluate()) +  " ** " + to_string(mult->evaluate()); }

Iterator* create_iterator() {
      Base* x = this;
      Iterator* temp = new BinaryIterator(x);
      return temp;
    }

    Base* get_left(){
      return op; 
    }

    Base* get_right(){
      return mult; 
    }

    void accept(CountVisitor* v){
      v->visit_pow();
    }
};





#endif
