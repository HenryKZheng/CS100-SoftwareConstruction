#ifndef MULT_TEST_HPP
#define MULT_TEST_HPP_

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"

TEST(MultTest, MultEvaluateZero) {
    Base* x = new Op(0);
    Base* y = new Op(0);
    Mult* test = new Mult(x, y);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNonZero) {
    Base* x = new Op(3);
    Base* y = new Op(3);
    Mult* test = new Mult(x, y);
    EXPECT_EQ(test->evaluate(), 9);
}

TEST(MultTest, MultEvaluateNegative) {
    Base* x = new Op(-1);
    Base* y = new Op(1);
    Mult* test = new Mult(x, y);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(MultTest, MultEvaluateString) {
    Base* x = new Op(-1);
    Base* y = new Op(1);
    Mult* test = new Mult(x, y);
    EXPECT_EQ(test->stringify(), "-1.000000*1.000000");
}
#endif
