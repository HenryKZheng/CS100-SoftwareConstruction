#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "Pow.hpp"
#include "op.hpp"

TEST(PowTest, PowEvaluateZero){
    Base* a = new Op(0);
    Base* b = new Op(0);
    Pow* test = new Pow(a, b);
    EXPECT_EQ(test->evaluate(), 1);
}


TEST(PowTest, PowEvaluateNegative){
    Base* a = new Op(-3);
    Base* b = new Op(3);
    Pow* test = new Pow(a, b);
    EXPECT_EQ(test->evaluate(), -27);
}

TEST(PowTest, PowEvaluateNonZero){
    Base* a = new Op(2);
    Base* b = new Op(5);
    Pow* test = new Pow(a, b);
    EXPECT_EQ(test->evaluate(), 32);
}

TEST(PowTest, PowEvaluateString){
    Base* a = new Op(8);
    Base* b = new Op(5);
    Pow* test = new Pow(a, b);
    EXPECT_EQ(test->stringify(), "8.000000 ** 5.000000");
}





#endif

