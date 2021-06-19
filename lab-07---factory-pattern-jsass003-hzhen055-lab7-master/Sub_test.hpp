#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "Sub.hpp"
#include "op.hpp"

TEST(SubTest, SubEvaluateZero){
    Base* a = new Op(0);
    Base* b = new Op(0);
    Sub* test = new Sub(a, b);
    EXPECT_EQ(test->evaluate(), 0);
}


TEST(SubTest, SubEvaluateNegative){
    Base* a = new Op(3);
    Base* b = new Op(5);
    Sub* test = new Sub(a, b);
    EXPECT_EQ(test->evaluate(), -2);
}


TEST(SubTest, SubEvaluateNonZero){
    Base* a = new Op(8);
    Base* b = new Op(5);
    Sub* test = new Sub(a, b);
    EXPECT_EQ(test->evaluate(), 3);
}

TEST(SubTest, SubEvaluateString){
    Base* a = new Op(8);
    Base* b = new Op(5);
    Sub* test = new Sub(a, b);
    EXPECT_EQ(test->stringify(), "8.000000 - 5.000000");
}





#endif
