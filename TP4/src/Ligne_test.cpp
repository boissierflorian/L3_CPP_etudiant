#include <CppUTest/CommandLineTestRunner.h>

#include "Ligne.hpp"

TEST_GROUP(GroupLigne) { };

TEST(GroupLigne, Ligne_test1) 
{
  Ligne ligne({1, 0, 0}, {0, 0}, {100, 200});
  CHECK_EQUAL(1, ligne.getCouleur()._r);
  CHECK_EQUAL(0, ligne.getCouleur()._g);
  CHECK_EQUAL(0, ligne.getCouleur()._b);
  CHECK_EQUAL(0, ligne.getP0()._x);
  CHECK_EQUAL(0, ligne.getP0()._y);
  CHECK_EQUAL(100, ligne.getP1()._x);
  CHECK_EQUAL(200, ligne.getP1()._y);
}
