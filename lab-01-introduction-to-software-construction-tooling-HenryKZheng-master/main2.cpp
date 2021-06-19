#include "c-echo.h"
#include <iostream>

using namespace std; 

int main(int argv, char** argc) {
    std::cout << echo(argv, argc) << endl;
}
