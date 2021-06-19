#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "Add.hpp"
#include "op.hpp"

TEST(AddTest, AddEvaluateZero){
    Base* a = new Op(0);
    Base* b = new Op(0);
    Add* test = new Add(a, b);
    EXPECT_EQ(test->evaluate(), 0);
}


TEST(AddTest, AddEvaluateNegative){
    Base* a = new Op(3);
    Base* b = new Op(-5);
    Add* test = new Add(a, b);
    EXPECT_EQ(test->evaluate(), -2);
}


TEST(AddTest, AddEvaluateNonZero){
    Base* a = new Op(8);
    Base* b = new Op(5);
    Add* test = new Add(a, b);
    EXPECT_EQ(test->evaluate(), 13);
}

TEST(AddTest, AddEvaluateString){
    Base* a = new Op(8);
    Base* b = new Op(5);
    Add* test = new Add(a, b);
    EXPECT_EQ(test->stringify(), "8.000000 + 5.000000");
}







#endif
