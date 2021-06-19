#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "SelectionSort.hpp"
#include "sort.hpp"
#include "VectorContainer.hpp"
#include "Factory.hpp"

TEST(FactoryTests, AddingZero){
  char* argv[4] = {"./test", "0", "+", "0"};
  
  Factory* tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(0, Testing->evaluate());
  EXPECT_EQ("0.000000 + 0.000000", Testing->stringify());
}

TEST(FactoryTests, AddingInteger){
  char* argv[4] = {"./test", "1", "+", "2"};
  

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(3, Testing->evaluate());
  EXPECT_EQ("1.000000 + 2.000000", Testing->stringify());
}

TEST(FactoryTests, SubtractingZero){
  char* argv[4] = {"./test", "0", "-", "0"};

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(0, Testing->evaluate());
  EXPECT_EQ("0.000000 - 0.000000", Testing->stringify());
}

TEST(FactoryTests, SubtractingInteger){
  char* argv[4] = {"./test", "4", "-", "2"};

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(2, Testing->evaluate());
  EXPECT_EQ("4.000000 - 2.000000", Testing->stringify());
}

TEST(FactoryTests, NullptrTest){
  VectorContainer test;
  char* argv[4] = {"./test", "-", "-", "2"};

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(nullptr, Testing);
}

TEST(FactoryTests, NullptrTestIncompleteExprsn){
  VectorContainer test;
  char* argv[4] = {"./test", "2", "-", "+"};

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(nullptr, Testing);
}
TEST(FactoryTests, MultZero){
  VectorContainer test;
  char* argv[4] = {"./test", "0", "*", "0"}; 
  

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(0, Testing->evaluate());
  EXPECT_EQ("0.000000*0.000000", Testing->stringify());
}

TEST(FactoryTests, MultInteger){
  char* argv[4] = {"./test", "4", "*", "3"}; 

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(12, Testing->evaluate());
  EXPECT_EQ("4.000000*3.000000", Testing->stringify());
}

TEST(FactoryTests, DivInteger){
  VectorContainer test;
  char* argv[4] = {"./test", "10", "/", "5"};

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(2, Testing->evaluate());
  EXPECT_EQ("10.000000/5.000000", Testing->stringify());
}

TEST(FactoryTests, MultIntegerMultipleDigits){
  VectorContainer test;
  char* argv[4] = {"./test", "100", "*", "5"};

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(500, Testing->evaluate());
  EXPECT_EQ("100.000000*5.000000", Testing->stringify());
}

TEST(FactoryTests, PowZero){
  VectorContainer test;
  char* argv[4] = {"./test", "5", "**", "0"}; 
 

  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(1, Testing->evaluate());
  EXPECT_EQ("5.000000 ** 0.000000", Testing->stringify());
}

TEST(FactoryTests, PowInteger){
  VectorContainer test;
  char* argv[4] = {"./test", "2", "**", "4"};


  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 4);
  EXPECT_EQ(16, Testing->evaluate());
  EXPECT_EQ("2.000000 ** 4.000000", Testing->stringify());
}

TEST(FactoryTests, TwoOperators){
  VectorContainer test;
  char **x; 
  char* argv[6] = {"./test", "2", "+", "4","*","3"}; 
  
  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 6);
  EXPECT_EQ(18, Testing->evaluate());
  EXPECT_EQ("2.000000 + 4.000000*3.000000", Testing->stringify());
}



TEST(FactoryTests, ThreeOperators){
  VectorContainer test;
  char* argv[8] = {"./test", "2", "+", "4", "*", "3", "/", "2"};
  
  Factory *tester = new Factory();
  Base* Testing = tester->parse(argv, 8);
  EXPECT_EQ(9, Testing->evaluate());
  EXPECT_EQ("2.000000 + 4.000000*3.000000/2.000000", Testing->stringify());
}


#endif

