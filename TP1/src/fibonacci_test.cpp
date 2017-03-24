#include "fibonacci.hpp"
#include <CppUTest/CommandLineTestRunner.h>

TEST_GROUP(GroupeFibo) { };

TEST(GroupeFibo, test_recursif_1) {
  int termes[5] = {1, 1, 2, 3, 5};

  for (unsigned int i = 0; i < 5; i++)
  {
    CHECK_EQUAL(termes[i], fibonacciRecursif(i));
  }
}

TEST(GroupeFibo, test_iteratif_1) {
  int termes[5] = {1, 1, 2, 3, 5};

  for (unsigned int i = 0; i < 5; i++)
  {
    CHECK_EQUAL(termes[i], fibonacciIteratif(i));
  }
}
