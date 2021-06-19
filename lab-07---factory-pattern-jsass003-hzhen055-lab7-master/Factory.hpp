#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_


#include "base.hpp"

#include <vector>
#include <iostream>

using namespace std;

class Base;

class Factory{
        public:
                /* Constructor */
                Factory(){};
                Base* parse(char** input, int length);
};

#endif
