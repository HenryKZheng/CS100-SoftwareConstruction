#ifndef __CONTAINER_LIST_TEST__
#define __CONTAINER_LIST_TEST__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"

#include "ContainerList.hpp"

TEST(ContainerListTests, AddIntegerTest){
	ContainerList*  test = new ContainerList();
	Base* x = new Op(10);
	test->add_element(x);
	Base* Testing = test->at(0);
	EXPECT_EQ(Testing->stringify(), "10.000000");
	delete x;
}

TEST(ContainerListTests, AddPlusTest){
        ContainerList*  test = new ContainerList();
        Base* x = new Op(10);
	Base* y = new Op(10);
	Base* z = new Add(x, y);
	test->add_element(x);
	test->add_element(y);
	test->add_element(z);

	Base* Testing = test->at(2);
        EXPECT_EQ(Testing->stringify(), "10.000000 + 10.000000");
        delete x;
	delete y;
	delete z;
}

TEST(ContainerListTests, AtPositionTest){
	ContainerList* test = new ContainerList();
	Base* x = new Op(2);
	Base* y = new Op(5);
	Base* z = new Mult(x, y);
	
	test->add_element(x);
	test->add_element(y);
	test->add_element(z);
	
	Base* Testing = test->at(1);
	EXPECT_EQ(Testing->stringify(), "5.000000");
	
	delete x;
        delete y;
        delete z;

}

TEST(ContainerListTests, SwapTest){
	ContainerList* test = new ContainerList();
	Base* x = new Op(6);
	Base* y = new Op(8);
	
	test->add_element(x);
	test->add_element(y);
	test->swap(0, 1);
	Base* Testing = test->at(0);
	EXPECT_EQ(Testing->stringify(), "8.000000");
	delete x;
	delete y;
}
	
TEST(ContainerListTests, SizeTest){
	ContainerList* test = new ContainerList();
	Base* x = new Op(3);
	Base* y = new Op(4);
	Base* z = new Op(5);
	
	test->add_element(x);
        test->add_element(y);
        test->add_element(z);

	 ASSERT_EQ(test->size(), 3);
}
	




#endif
