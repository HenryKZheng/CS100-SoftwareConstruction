#include "BubbleSort.hpp"
#include "base.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Pow.hpp"
#include "op.hpp"
#include "Sub.hpp"
#include "sort.hpp"
using namespace std; 

class Container; //declare this whenever u want to access smt aka friedn class

void BubbleSort::sort(Container* container){
	int i, j;
	int n = container->size();  
	bool flag; 
	for(unsigned int i = 0; i < n-1;++i)
	{
		flag = false; 
		for(unsigned j = 0; j < n-i-1; ++j)
		{
			if(container->at(j)->evaluate() > container->at(j+1)->evaluate())
			{
				container->swap(j,j+1);
				flag = true; 
			}
		}
		if(flag == false)
		{break;}
	} 	
}
