#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include <vector>

class Sort;
class Base;

using namespace std; 

class VectorContainer: public Container {
	private:
		std::vector<Base* > trees;
		//Sort* sort_function; maybe we don't need it? 
	public: 
		VectorContainer():Container(){};
		VectorContainer(Sort* function):Container(function){}//just to instantiate things easier (for testing)
		
	/* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm

	/* Pure Virtual Functions */
	// push the top pointer of the tree into container
	void add_element(Base* element);
	// iterate through trees and output the expressions (use stringify())
	void print();
	// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
	void sort();
	
	/* Essentially the only functions needed to sort */
        //switch tree locations
        void swap(int i, int j);
	// get top ptr of tree at index i
	Base* at(int i);
	// return container size
	int size();	
};
#endif

