#ifndef RAND__TEST_HPP
#define RAND__TEST_HPP_

#include "gtest/gtest.h"
#include "Rand.hpp"
#include <string>

using namespace std;

TEST(RandTest, RandTestEvaluate) {
    double value = 3 + (rand() % 100); 
    Rand* test = new Rand();
    EXPECT_EQ(test->evaluate(), value);
}

TEST(RandTest, RandTestStringify) {
    double random = rand() %100;
    string rando = to_string(random);
    Rand* test = new Rand();
    EXPECT_EQ(test->stringify(),"15.000000");
}
TEST(RandTest, RandTestEvaluateGTZero) {
    Rand* test = new Rand();
    EXPECT_GT(test->evaluate(), 0);
}
TEST(RandTest, RandTestEvaluateLT99) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 99);
}
#endif
