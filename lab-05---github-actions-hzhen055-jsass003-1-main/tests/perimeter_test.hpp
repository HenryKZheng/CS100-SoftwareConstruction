#ifndef __PERIMETER_TEST_HPP__
#define __PERIMETER_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

using namespace std;


TEST(PerimeterTest, ZeroPerimeterTest){
	Rectangle rect(0, 0);
	EXPECT_EQ(rect.perimeter(), 0);
}

//should be 50 not 49
TEST(PerimeterTest, NormalPerimeterTest){
	Rectangle rect(11, 14);
	EXPECT_EQ(rect.perimeter(), 50);
}

TEST(PerimeterTest, NegativePerimeterTest){
	Rectangle rect(-1, -8);
	EXPECT_EQ(rect.perimeter(), -18);
}

TEST(PerimeterTest,  BigPerimeterTest){
	Rectangle rect(4545, 5000);
	EXPECT_EQ(rect.perimeter(),19090);	
	
}



#endif
