#ifndef DIV_TEST_HPP
#define DIV_TEST_HPP_

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "Div.hpp"

TEST(DivTest, DivEvaluateZeroNum) {
    Base* x = new Op(0);
    Base* y = new Op(1);
    Div* test = new Div(x, y);
    EXPECT_EQ(test->evaluate(), 0);
}
TEST(DivTest, DivEvaluateRegNum) {
    Base* x = new Op(2);
    Base* y = new Op(1);
    Div* test = new Div(x, y);
    EXPECT_EQ(test->evaluate(), 2);

}
TEST(DivTest, DivEvaluateNegative) {
    Base* x = new Op(-3);
    Base* y = new Op(1);
    Div* test = new Div(x, y);
    EXPECT_EQ(test->evaluate(), -3);
}
TEST(DivTest, DivEvaluateStringify) {
    Base* x = new Op(3);
    Base* y = new Op(2);
    Div* test = new Div(x, y);
    EXPECT_EQ(test->stringify(), "3.000000/2.000000");
}
#endif
