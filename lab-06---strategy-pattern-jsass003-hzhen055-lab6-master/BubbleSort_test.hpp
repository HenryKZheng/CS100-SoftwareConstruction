#ifndef _BUBBLE_SORT_TEST_HPP
#define _BUBBLE_SORT_TEST_HPP_

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "BubbleSort.hpp"
#include "sort.hpp"
#include "VectorContainer.hpp"
#include "ContainerList.hpp"
using namespace std; 

TEST(BubbleSortTests, TestingSort){
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Base* TreeA = new Mult(seven, four);

	Op* three = new Op(3);
	Op* two = new Op(2);
	Base* TreeB = new Add(three, two);
	
	Op* ten = new Op(10);
	Op* six = new Op(6);
	Base* TreeC = new Sub(ten, six);

	VectorContainer* container = new VectorContainer(); 
	container->add_element(TreeA);
	container->add_element(TreeB); 
	container->add_element(TreeC);

	Sort *temp = new BubbleSort(); 
	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 28);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 4);
	container->set_sort_function(temp);
	container->sort();

	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 28);
}
TEST(BubbleSortTests, TestingSortNegativesMult){
        Op* seven = new Op(-7);
        Op* four = new Op(4);
        Base* TreeA = new Mult(seven, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Base* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Base* TreeC = new Sub(ten, six);

        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        Sort *temp = new BubbleSort();
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), -28);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 4);
        container->set_sort_function(temp);
        container->sort();

        EXPECT_EQ(container->at(0)->evaluate(), -28);
        EXPECT_EQ(container->at(1)->evaluate(), 4);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
}
TEST(BubbleSortTests, TestingSortAllNegatives){
        Op* seven = new Op(-7);
        Op* four = new Op(-4);
        Base* TreeA = new Mult(seven, four);

        Op* three = new Op(-3);
        Op* two = new Op(-2);
        Base* TreeB = new Add(three, two);

        Op* ten = new Op(-10);
        Op* six = new Op(-6);
        Base* TreeC = new Sub(ten, six);

        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        Sort *temp = new BubbleSort();
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 28);
        EXPECT_EQ(container->at(1)->evaluate(), -5);
        EXPECT_EQ(container->at(2)->evaluate(), -4);
        container->set_sort_function(temp);
        container->sort();

        EXPECT_EQ(container->at(0)->evaluate(), -5);
        EXPECT_EQ(container->at(1)->evaluate(), -4);
        EXPECT_EQ(container->at(2)->evaluate(), 28);
}
TEST(BubbleSortTests, TestingSortAllZeros){
        Op* seven = new Op(0);
        Op* four = new Op(0);
        Base* TreeA = new Mult(seven, four);

        Op* three = new Op(0);
        Op* two = new Op(0);
        Base* TreeB = new Add(three, two);

        Op* ten = new Op(0);
        Op* six = new Op(0);
        Base* TreeC = new Sub(ten, six);

        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        Sort *temp = new BubbleSort();
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 0);
        EXPECT_EQ(container->at(1)->evaluate(), 0);
        EXPECT_EQ(container->at(2)->evaluate(), 0);
        container->set_sort_function(temp);
        container->sort();

        EXPECT_EQ(container->at(0)->evaluate(), 0);
        EXPECT_EQ(container->at(1)->evaluate(), 0);
        EXPECT_EQ(container->at(2)->evaluate(), 0);
}

TEST(BubbleSortTests, TestingSortContainerList){
        Op* seven = new Op(7);
        Op* four = new Op(4);
        Base* TreeA = new Mult(seven, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Base* TreeB = new Add(three, two);

        Op* ten = new Op(10);
        Op* six = new Op(6);
        Base* TreeC = new Sub(ten, six);

        ContainerList* container = new ContainerList();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        Sort *temp = new BubbleSort();
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 28);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 4);
        container->set_sort_function(temp);
        container->sort();

        EXPECT_EQ(container->at(0)->evaluate(), 4);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 28);
}


#endif
