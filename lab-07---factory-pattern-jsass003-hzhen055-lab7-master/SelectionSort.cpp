#include "SelectionSort.hpp"

#include "base.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Pow.hpp"
#include "op.hpp"
#include "Sub.hpp"
#include "sort.hpp" 

class Container; 


void SelectionSort::sort(Container* container){
	int i, j, first;
	int length = container->size();
	for(i = 0;i < length -1; i++)
	{
		first = i; 
		for(j = i+1; j < length; j++){
			if(container->at(j)->evaluate() < container->at(first)->evaluate()){
				first=j;
			}
		}
		container->swap(first, i);
	}
}



