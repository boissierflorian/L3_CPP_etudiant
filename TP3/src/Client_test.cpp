#include <CppUTest/CommandLineTestRunner.h>

#include "Client.hpp"

TEST_GROUP(GroupClient) { };

TEST(GroupClient, Client_test1) 
{
  Client c{42, "blabla"};
  CHECK_EQUAL(42, c.getId());
  CHECK_EQUAL("blabla", c.getNom());
}
