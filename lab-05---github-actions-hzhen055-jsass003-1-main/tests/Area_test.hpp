#ifndef AREA_TEST_HPP
#define AREA_TEST_HPP
#include "gtest/gtest.h"
#include "../header/rectangle.hpp"




//should be 0 not 1
TEST(AreaTest, AreaTestDefaultHeight){
        Rectangle* x = new Rectangle();
        EXPECT_EQ(x->area(), 0);
}

TEST(AreaTest, AreaTestNormal){
        Rectangle* x = new Rectangle(10,5);
        EXPECT_EQ(x->area(),50);
}

TEST(AreaTest, AreaTestNegative){
        Rectangle* x = new Rectangle(-10,5);
        EXPECT_EQ(x->area(),-50);
}

TEST(AreaTest, AreaTestZero){
        Rectangle* x = new Rectangle(0,0);
        EXPECT_EQ(x->area(),0);
}

#endif
