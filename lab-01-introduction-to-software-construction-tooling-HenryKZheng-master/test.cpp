#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, Numbers) {
    char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "123"; 
    EXPECT_EQ("123", echo(2, test_val));
}

TEST(EchoTest, SameWord) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "one"; test_val[2] = "one";
    EXPECT_EQ("one one", echo(3, test_val));
}

TEST(EchoTest, BigDigits) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "123"; test_val[2] = "456";
    EXPECT_EQ("123 456", echo(3, test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
