#include "VectorContainer.hpp"
#include <iostream>

#include <vector>
 
using namespace std; 

class Sort; //friend classes-> this is how we declare them to access them!
class Base; 

void VectorContainer::set_sort_function(Sort *sort_function)
{
	this->sort_function = sort_function; //sort_function member declared in Base class
}

void VectorContainer::add_element(Base *element)
{
	trees.push_back(element);
}

void VectorContainer::print()
{
	for(unsigned int i = 0; i < trees.size();++i){
		trees.at(i)->stringify();
		cout << endl;  
	}
}

void VectorContainer::sort()
{
	sort_function->sort(this); 
}

void VectorContainer::swap(int i, int j)
{
	Base* temp = trees.at(i);
	trees.at(i) = trees.at(j);
	trees.at(j) = temp; 
}

Base* VectorContainer::at(int i)
{
	return trees.at(i);
}

int VectorContainer::size()
{
	return trees.size(); 
}
