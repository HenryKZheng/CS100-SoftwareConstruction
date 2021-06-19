#ifndef __SELECTION_SORT_TEST_HPP__
#define __SELECTION_SORT_TEST_HPP__


#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "SelectionSort.hpp"
#include "sort.hpp"
#include "ContainerList.hpp"

using namespace std; 

TEST(SelectionSortTests, TestingSort){
	Op* eight = new Op(8);
	Op* three = new Op(3);
	Base* TreeA = new Mult(eight, three);

	Op* six = new Op(6);
	Op* one = new Op(1);
	Base* TreeB = new Add(six, one);
	
	Op* nine = new Op(9);
	Op* five = new Op(5);
	Base* TreeC = new Sub(nine, five);

	ContainerList* container = new ContainerList(); 
	container->add_element(TreeA);
	container->add_element(TreeB); 
	container->add_element(TreeC);

//	Sort *temp = new SelectionSort(); 
	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 24);
	EXPECT_EQ(container->at(1)->evaluate(), 7);
	EXPECT_EQ(container->at(2)->evaluate(), 4);
	container->set_sort_function(new SelectionSort());
	container->sort();

	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 7);
	EXPECT_EQ(container->at(2)->evaluate(), 24);
}
TEST(SelectionSortTests, TestingSortNegativesMult){
        Op* five = new Op(-5);
        Op* four = new Op(4);
        Base* TreeA = new Mult(five, four);

        Op* three = new Op(3);
        Op* two = new Op(2);
        Base* TreeB = new Add(three, two);

        Op* seven = new Op(7);
        Op* six = new Op(6);
        Base* TreeC = new Sub(seven, six);

        ContainerList* container = new ContainerList();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

 //       Sort *temp = new SelectionSort();
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), -20);
        EXPECT_EQ(container->at(1)->evaluate(), 5);
        EXPECT_EQ(container->at(2)->evaluate(), 1);
        container->set_sort_function(new SelectionSort());
        container->sort();

        EXPECT_EQ(container->at(0)->evaluate(), -20);
        EXPECT_EQ(container->at(1)->evaluate(), 1);
        EXPECT_EQ(container->at(2)->evaluate(), 5);
}
TEST(SelectionSortTests, TestingSortAllNegatives){
        Op* third = new Op(-3);
        Op* four = new Op(-4);
        Base* TreeA = new Mult(third, four);

        Op* three = new Op(-3);
        Op* two = new Op(-2);
        Base* TreeB = new Add(three, two);

        Op* nine = new Op(-9);
        Op* six = new Op(-6);
        Base* TreeC = new Sub(nine, six);

        ContainerList* container = new ContainerList();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        Sort *temp = new SelectionSort();
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 12);
        EXPECT_EQ(container->at(1)->evaluate(), -5);
        EXPECT_EQ(container->at(2)->evaluate(), -3);
        container->set_sort_function(temp);
        container->sort();

        EXPECT_EQ(container->at(0)->evaluate(), -5);
        EXPECT_EQ(container->at(1)->evaluate(), -3);
        EXPECT_EQ(container->at(2)->evaluate(), 12);
}
TEST(SelectionSortTests, TestingSortAllZeros){
        Op* seven = new Op(0);
        Op* four = new Op(0);
        Base* TreeA = new Mult(seven, four);

        Op* three = new Op(0);
        Op* two = new Op(0);
        Base* TreeB = new Add(three, two);

        Op* ten = new Op(0);
        Op* six = new Op(0);
        Base* TreeC = new Sub(ten, six);

        ContainerList* container = new ContainerList();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

        Sort *temp = new SelectionSort();
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

TEST(SelectionSortTests, TestingSortWithVectorContainer){
        Op* eight = new Op(8);
        Op* three = new Op(3);
        Base* TreeA = new Mult(eight, three);

        Op* six = new Op(6);
        Op* one = new Op(1);
        Base* TreeB = new Add(six, one);

        Op* nine = new Op(9);
        Op* five = new Op(5);
        Base* TreeC = new Sub(nine, five);

        VectorContainer* container = new VectorContainer();
        container->add_element(TreeA);
        container->add_element(TreeB);
        container->add_element(TreeC);

	Sort *temp = new SelectionSort(); 
        ASSERT_EQ(container->size(), 3);
        EXPECT_EQ(container->at(0)->evaluate(), 24);
        EXPECT_EQ(container->at(1)->evaluate(), 7);
         EXPECT_EQ(container->at(2)->evaluate(), 4);
       container->set_sort_function(new SelectionSort());
         container->sort();

       EXPECT_EQ(container->at(0)->evaluate(), 4);
       EXPECT_EQ(container->at(1)->evaluate(), 7);
       EXPECT_EQ(container->at(2)->evaluate(), 24);
        }




#endif
