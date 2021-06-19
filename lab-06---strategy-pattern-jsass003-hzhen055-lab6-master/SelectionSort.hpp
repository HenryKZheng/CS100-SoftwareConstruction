#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "sort.hpp"
#include "container.hpp"
#include <iostream>

class Container;
class Sort;

class SelectionSort: public Sort{

	public:

	SelectionSort():Sort(){};
	
	void sort(Container* container);
};





#endif
