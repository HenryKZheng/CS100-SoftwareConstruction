#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "SevenOpMock.hpp"
#include "FirstOpMock.hpp"
#include "SecondOpMock.hpp"
TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateStringify) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(),"8.000000");
}

TEST(OpTest, OpEvaluateDecimal){
    SevenOpMock* test = new SevenOpMock(7.5);
    EXPECT_EQ(test->evaluate(), 7.5);
}


TEST(OpTest, OpEvaluateNegative){
    FirstOpMock* test = new FirstOpMock(-1);
    EXPECT_EQ(test->evaluate(), -1);
}

TEST(OpTest, OpEvaluateZero){
    SecondOpMock* test = new SecondOpMock(0);
    EXPECT_EQ(test->evaluate(), 0);
}

#endif //__OP_TEST_HPP__
