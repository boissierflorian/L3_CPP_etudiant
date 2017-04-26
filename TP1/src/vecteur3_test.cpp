#include "vecteur3.hpp"
#include <CppUTest/CommandLineTestRunner.h>
#include <cmath>

TEST_GROUP(GroupeVec) { };

TEST(GroupeVec, test_vec_1) {
  Vecteur3 v {1, 2, 3};

  CHECK_EQUAL(1, v._x);
  CHECK_EQUAL(2, v._y);
  CHECK_EQUAL(3, v._z);
}

TEST(GroupeVec, test_vec_2) {
  Vecteur3 v {4, 2, 4};
  
  CHECK_EQUAL(6, v.norme());
}

TEST(GroupeVec, test_vec_3) {
  Vecteur3 v{1, 2, 2};
  Vecteur3 x{-1, -2, -2};
  
  CHECK_EQUAL(0, addition(v, x));  
}

TEST(GroupeVec, test_vec_4) {
  Vecteur3 v{1, 2, 2};
  Vecteur3 x{2, 1, 0};
  
  CHECK_EQUAL(4, produitScalaire(v, x));  
}
