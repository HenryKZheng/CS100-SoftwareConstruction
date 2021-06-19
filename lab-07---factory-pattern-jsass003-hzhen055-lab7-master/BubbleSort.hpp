#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class Container;

class BubbleSort: public Sort {
    public:
        /* Constructors */
        BubbleSort():Sort(){};

        /* Pure Virtual Functions */
        void sort(Container* container);
};

#endif //__SORT_HPP__
