#include "gtest/gtest.h"
#include "perimeter_test.hpp"
#include "../header/rectangle.hpp"
#include "Area_test.hpp"
#include "Constructors_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
