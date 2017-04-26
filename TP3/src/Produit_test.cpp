#include <CppUTest/CommandLineTestRunner.h>

#include "Produit.hpp"

TEST_GROUP(GroupProduit) { };

TEST(GroupProduit, Produit_test1) 
{
  Produit p{0, "un produit"};
  CHECK_EQUAL(0, p.getId());
  CHECK_EQUAL("un produit", p.getDescription());
}
