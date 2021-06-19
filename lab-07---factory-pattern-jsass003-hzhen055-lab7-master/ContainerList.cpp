#include "ContainerList.hpp"
using namespace std;
class Sort;
class Base;


void ContainerList::set_sort_function(Sort* sort_function){
	this->sort_function = sort_function;
}

void ContainerList::add_element(Base* element){
	treeList.push_back(element);
}

void ContainerList::sort(){
	sort_function->sort(this);
}

void ContainerList::swap(int i, int j){
	list<Base *>::iterator first = treeList.begin();
	list<Base *>::iterator second = treeList.begin();
	for(unsigned int x = 0; x<i; ++x){
		first++; 
	}
	for(unsigned int y = 0; y<j; ++y){
                second++;
        }
	Base* temp = *first; 
	*first = *second;
	*second = temp;
/*	auto first = std::next(treeList.begin(), i);
    	auto second = std::next(treeList.begin(), j);
    	std::iter_swap(first, second);*/	


}

Base* ContainerList::at(int i){
	std::list<Base*>::iterator it;
	int cntr =0;
	for(it = treeList.begin(); it != treeList.end(); ++it){
		if(cntr == i){
			return *it;
		}
	cntr++;
	}
	return nullptr;
		

}

int ContainerList::size(){
	return treeList.size();
}

void ContainerList::print(){
	std::list<Base*>::iterator it;
	for(it = treeList.begin(); it != treeList.end(); ++it){
		cout << (*it)->stringify() << endl; 
	}
}
