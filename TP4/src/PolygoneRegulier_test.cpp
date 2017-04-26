#include <CppUTest/CommandLineTestRunner.h>

#include "PolygoneRegulier.hpp"
#include "Couleur.hpp"
#include "Point.hpp"

TEST_GROUP(GroupPolygoneRegulier) { };

TEST(GroupPolygoneRegulier, PolygoneRegulier_test1) 
{
  PolygoneRegulier poly({0, 1, 0}, {100, 200}, 50, 5);
  const Couleur& c = poly.getCouleur();

  // Vérification de la couleur
  CHECK_EQUAL(0, c._r);
  CHECK_EQUAL(1, c._g);
  CHECK_EQUAL(0, c._b);

  // Vérification du nombre de points
  CHECK_EQUAL(5, poly.getNbPoints());
}


TEST(GroupPolygoneRegulier, PolygoneRegulier_test2) 
{
  PolygoneRegulier poly({0, 1, 0}, {100, 200}, 50, 5);
  int x[] = {150, 115, 59, 59, 115};
  int y[] = {200, 247, 229, 170, 152};

  for (int i = 0; i < poly.getNbPoints(); i++)
  {
    CHECK_EQUAL(x[i], poly.getPoint(i)._x);
    CHECK_EQUAL(y[i], poly.getPoint(i)._y);
  }
}

