#ifndef __CONTAINER_LIST_HPP__
#define __CONTAINER_LIST_HPP__

#include "container.hpp"
#include "base.hpp"
#include <iostream>
#include <list>

class Base;
class Sort;


class ContainerList: public Container {
 private: 
	std::list<Base*> treeList;
	
 public:
	//Constructors
	ContainerList():Container() {};
	ContainerList(Sort* function):Container(function){}
	

	/* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm

	/* Virtual Functions */
	//push the top pointer of the tree into the container
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
