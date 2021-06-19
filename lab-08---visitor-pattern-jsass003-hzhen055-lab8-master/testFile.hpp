
#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__
#include "gtest/gtest.h"

#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "Rand.hpp"
#include "Div.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

TEST(NewBaseClasses, TestingLeftRight) {
    Base* num1 = new Op(2.0);
    Base* num2 = new Op(-3.0); 
    Base* m = new Mult(num1, num2);

    EXPECT_EQ(m->get_left(), num1);
    EXPECT_EQ(m->get_right(), num2);
    delete num1;
    delete num2;
}
TEST(NewBaseClasses, TestingNullIterator) {
    Base* num1 = new Op(5.0);
    Iterator* test = num1->create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->is_done(), true);
    EXPECT_EQ(test->current(), nullptr);
    delete test;

    num1 = new Rand();
    Iterator* test2 = num1->create_iterator();

    ASSERT_NE(test2, nullptr);
    EXPECT_EQ(test2->is_done(), true);
    EXPECT_EQ(test2->current(), nullptr);
    delete test2;
}
TEST(NewBaseClasses, TestingBinaryIteratorMult) {
    Base* num1 = new Op(3.0);
    Base* num2 = new Op(5.0);
    Mult m(num1, num2);
    Iterator* test = m.create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->current(), num1);
    test->next();
    EXPECT_EQ(test->current(), num2);
    EXPECT_EQ(test->is_done(), false);
    test->next();
    test->next();
    EXPECT_EQ(test->current(), nullptr);
    EXPECT_EQ(test->is_done(), true);
    test->first();
    EXPECT_EQ(test->current(), num1);
    delete test;
    delete num1;
    delete num2;
}
TEST(NewBaseClasses, TestingBinaryIteratorDiv) {
    Base* num1 = new Op(2.0);
    Base* num2 = new Op(-7.0);
    Div d(num1, num2);
    Iterator* test = d.create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->current(), num1);
    test->next();
    EXPECT_EQ(test->current(), num2);
    EXPECT_EQ(test->is_done(), false);
    test->next();
    test->next();
    EXPECT_EQ(test->current(), nullptr);
    EXPECT_EQ(test->is_done(), true);
    test->first();
    EXPECT_EQ(test->current(), num1);
    delete test;
    delete num1;
    delete num2;
}
TEST(NewBaseClasses, TestingBinaryIteratorAdd) {
    Base* num1 = new Op(1.0);
    Base* num2 = new Op(-9.0);
    Add a(num1, num2);
    Iterator* test = a.create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->current(), num1);
    test->next();
    EXPECT_EQ(test->current(), num2);
    EXPECT_EQ(test->is_done(), false);
    test->next();
    test->next();
    EXPECT_EQ(test->current(), nullptr);
    EXPECT_EQ(test->is_done(), true);
    test->first();
    EXPECT_EQ(test->current(), num1);
    delete test;
    delete num1;
    delete num2;
}
TEST(NewBaseClasses, TestingBinaryIteratorSub) {
    Base* num1 = new Op(9.0);
    Base* num2 = new Op(-1.0);
    Sub s(num1, num2);
    Iterator* test = s.create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->current(), num1);
    test->next();
    EXPECT_EQ(test->current(), num2);
    EXPECT_EQ(test->is_done(), false);
    test->next();
    test->next();
    EXPECT_EQ(test->current(), nullptr);
    EXPECT_EQ(test->is_done(), true);
    test->first();
    EXPECT_EQ(test->current(), num1);
    delete test;
    delete num1;
    delete num2;
}

TEST(NewBaseClasses, TestingBinaryIteratorPow) {
    Base* num1 = new Op(5.0);
    Base* num2 = new Op(-8.0);
    Pow x(num1, num2);
    Iterator* test = x.create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->current(), num1);
    test->next();
    EXPECT_EQ(test->current(), num2);
    EXPECT_EQ(test->is_done(), false);
    test->next();
    test->next();
    EXPECT_EQ(test->current(), nullptr);
    EXPECT_EQ(test->is_done(), true);
    test->first();
    EXPECT_EQ(test->current(), num1);
    delete test;
    delete num1;
    delete num2;
}


/*TEST(NewBaseClasses, TestingBinaryIteratorLargeTree) {
    Base* num1 = new Op(3.0);
    Base* num2 = new Op(-4.0);
    Pow a(num1, num2);

    Base* num3 = new Op(2.0);
    Base* num4 = new Op(1.0);
    Pow b(num3, num4);

    Add x(a, b);

    Iterator* test = x.create_iterator();

    ASSERT_NE(test, nullptr);
    EXPECT_EQ(test->current(), a);
    test->next();

    EXPECT_EQ(test->current(), num1);
    EXPECT_EQ(test->is_done(), false);
    test->next();

    EXPECT_EQ(test->current(), num2);
    EXPECT_EQ(test->is_done(), false);
    test->next();

    EXPECT_EQ(test->current(), b);
    EXPECT_EQ(test->is_done(), false);
    test->next();

    EXPECT_EQ(test->current(), num3);
    EXPECT_EQ(test->is_done(), false);
    test->next();
  
    EXPECT_EQ(test->current(), num4);
    EXPECT_EQ(test->is_done(), false);
    test->next();
    test->next();

    EXPECT_EQ(test->current(), nullptr);
    EXPECT_EQ(test->is_done(), true);
    test->first();
    EXPECT_EQ(test->current(), num1);
    delete test;
    delete num1;
    delete num2;
    delete num3;
    delete num4;
}*/


TEST(VisitorTests, Constructors) {
    CountVisitor v;
    EXPECT_EQ(v.op_count(), 0);
    EXPECT_EQ(v.rand_count(), 0);
    EXPECT_EQ(v.mult_count(), 0);
    EXPECT_EQ(v.div_count(), 0);
    EXPECT_EQ(v.add_count(), 0);
    EXPECT_EQ(v.sub_count(), 0);
    EXPECT_EQ(v.pow_count(), 0);
}

TEST(VisitorTests, IncrementVisitTwice) {
    CountVisitor v;
    ASSERT_EQ(v.op_count(), 0);
    ASSERT_EQ(v.rand_count(), 0);
    ASSERT_EQ(v.mult_count(), 0);
    ASSERT_EQ(v.div_count(), 0);
    ASSERT_EQ(v.add_count(), 0);
    ASSERT_EQ(v.sub_count(), 0);
    ASSERT_EQ(v.pow_count(), 0);

    v.visit_op();
    v.visit_op();
    EXPECT_EQ(v.op_count(), 2);

    v.visit_rand();
    v.visit_rand();
    EXPECT_EQ(v.rand_count(), 2);

    v.visit_mult();
    v.visit_mult();
    EXPECT_EQ(v.mult_count(), 2);

    v.visit_div();
    v.visit_div();
    EXPECT_EQ(v.div_count(), 2);

    v.visit_add();
    v.visit_add();
    EXPECT_EQ(v.add_count(), 2);

    v.visit_sub();
    v.visit_sub();
    EXPECT_EQ(v.sub_count(), 2);

    v.visit_pow();
    v.visit_pow();
    EXPECT_EQ(v.pow_count(), 2);
}

TEST(VisitorTests, IncrementVisitThree) {
    CountVisitor v;
    ASSERT_EQ(v.op_count(), 0);
    ASSERT_EQ(v.rand_count(), 0);
    ASSERT_EQ(v.mult_count(), 0);
    ASSERT_EQ(v.div_count(), 0);
    ASSERT_EQ(v.add_count(), 0);
    ASSERT_EQ(v.sub_count(), 0);
    ASSERT_EQ(v.pow_count(), 0);

    v.visit_op();
    v.visit_op();
    v.visit_op();
    EXPECT_EQ(v.op_count(), 3);

    v.visit_rand();
    v.visit_rand();
    v.visit_rand();
    EXPECT_EQ(v.rand_count(), 3);

    v.visit_mult();
    v.visit_mult();
    v.visit_mult();
    EXPECT_EQ(v.mult_count(), 3);

    v.visit_div();
    v.visit_div();
    v.visit_div();
    EXPECT_EQ(v.div_count(), 3);

    v.visit_add();
    v.visit_add();
    v.visit_add();
    EXPECT_EQ(v.add_count(), 3);

    v.visit_sub();
    v.visit_sub();
    v.visit_sub();
    EXPECT_EQ(v.sub_count(), 3);

    v.visit_pow();
    v.visit_pow();
    v.visit_pow();
    EXPECT_EQ(v.pow_count(), 3);
}



TEST(VisitorTests, OneOperand) {
    Base* op1 = new Op(1.0);
    Base* op = new Rand();
    Base* dummy = new Mult(op1, op);
    CountVisitor* v = new CountVisitor();

    PreorderIterator p_iter(dummy);
    p_iter.first();
    while (!p_iter.is_done()) {
        p_iter.current()->accept(v);
        p_iter.next();
    }
    EXPECT_EQ(v->op_count(), 1);
}



TEST(VisitorTests, TreeFormationTest){
  Base* num1 = new Op(3.0);
  Base* num2 = new Op(-4.0);
  Base* a = new Pow(num1, num2);

  Base* num3 = new Op(2.0);
  Base* num4 = new Op(1.0);
  Base* b = new Pow(num3, num4);

  CountVisitor* v = new CountVisitor(); 

  Base* x = new Add(a, b);
  v->visit_add();
  PreorderIterator p_iter(x);
  p_iter.first(); 
  /*"shrinks" stack and gets first element in tree*/

  while (!p_iter.is_done()) {
    p_iter.current()->accept(v);
    p_iter.next();
  }
  EXPECT_EQ(v->op_count(), 4);
  EXPECT_EQ(v->pow_count(), 2);
  EXPECT_EQ(v->add_count(), 1);
}

#endif
