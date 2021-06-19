#ifndef VECTOR_CONTAINER_TEST_HPP
#define VECTOR_CONTAINER_TEST_HPP_

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
//#include "Mult.hpp"

#include "VectorContainer.hpp"

TEST(VectorContainerTestSet, AddIntegerTest) {
	VectorContainer test; 
	Base* A = new Op(7);
	test.add_element(A);
	Base* Testing = test.at(0);
	EXPECT_EQ("7.000000", Testing->stringify());
	delete A; 
}


TEST(VectorContainerTestSet, AddnMultiTest) {

        VectorContainer test;
        Base* A = new Op(7);
	Base* B = new Op(1);
	Base* C = new Mult(A,B);

        test.add_element(A);
	test.add_element(B);
	test.add_element(C);

        Base* Testing = test.at(2);
        EXPECT_EQ("7.000000*1.000000", Testing->stringify());
	
        delete A;
	delete B;
	delete C;  
}


TEST(VectorContainerTestSet, SwapTest) {
        VectorContainer test;
        Base* A = new Op(7);
	Base* B = new Op(5);
        test.add_element(A);
	test.add_element(B);
	test.swap(0,1);
        Base* Testing = test.at(0);
        EXPECT_EQ("5.000000", Testing->stringify());
        delete A;
	delete B; 
}

TEST(VectorContainerTestSet, AtTest) {

        VectorContainer test;
        Base* A = new Op(7);
        Base* B = new Op(1);
        Base* C = new Mult(A,B);

        test.add_element(A);
        test.add_element(B);
        test.add_element(C);

        Base* Testing = test.at(1);
        EXPECT_EQ("1.000000", Testing->stringify());

        delete A;
        delete B;
        delete C;
}
TEST(VectorContainerTestSet, SizeTest) {

        VectorContainer test;
        Base* A = new Op(7);
        Base* B = new Op(1);
        Base* C = new Mult(A,B);

        test.add_element(A);
        test.add_element(B);
        test.add_element(C);

        Base* Testing = test.at(1);
        ASSERT_EQ(test.size(), 3);

        delete A;
        delete B;
        delete C;
}

#endif
