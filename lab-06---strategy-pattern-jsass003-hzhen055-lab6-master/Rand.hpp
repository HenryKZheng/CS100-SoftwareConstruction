#ifndef _RAND_HPP_
#define _RAND_HPP_

#include "base.hpp"
#include <string>
#include "op.hpp"
using namespace std; 
class Rand: public Base{
	private:
		double value = rand() % 100; 
	public:
		Rand(){};
		virtual double evaluate() { return value; }
		virtual std::string stringify() { return std::to_string(value); }
	
};
#endif
