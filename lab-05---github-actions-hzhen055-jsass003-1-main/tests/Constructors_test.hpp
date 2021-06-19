#ifndef CONSTRUCTOR_TEST_HPP
#define CONSTRUCTOR_TEST_HPP

#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

TEST(ConstructorTest, ConstructorTestDefaultHeight){
	Rectangle* x = new Rectangle();
	EXPECT_EQ(x->get_height(), 0);
}

TEST(ConstructorTest, ConstructorTestDefaultWidth){
        Rectangle* x = new Rectangle();
        EXPECT_EQ(x->get_width(), 0);
}

//should return 10 not 11
TEST(ConstructorTest, ConstructorTestWidth){
        Rectangle* x = new Rectangle(10,5);
        EXPECT_EQ(x->get_width(), 10);
}

TEST(ConstructorTest, ConstructorTestHeight){
        Rectangle* x = new Rectangle(10,5);
        EXPECT_EQ(x->get_height(), 5);
}

#endif
