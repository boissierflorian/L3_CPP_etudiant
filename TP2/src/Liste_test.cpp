#include <CppUTest/CommandLineTestRunner.h>

#include "Liste.hpp"

TEST_GROUP(GroupListe) { };

TEST(GroupListe, test1) 
{ 
  Liste liste;
  liste.ajouterDevant(10);
  CHECK_EQUAL(10, liste._tete->_valeur);
}

TEST(GroupListe, test2)
{
  Liste liste;
  CHECK_EQUAL(0, liste.getTaille());
  liste.ajouterDevant(10);
  liste.ajouterDevant(20);
  liste.ajouterDevant(30);
  liste.ajouterDevant(40);
  CHECK_EQUAL(4, liste.getTaille());
}

TEST(GroupListe, test3)
{
  Liste liste;
  liste.ajouterDevant(10);
  liste.ajouterDevant(20);
  liste.ajouterDevant(30);
  liste.ajouterDevant(40);
  CHECK_EQUAL(NOEUD_INVALIDE, liste.getElement(-1));
  CHECK_EQUAL(NOEUD_INVALIDE, liste.getElement(4));
  CHECK_EQUAL(40, liste.getElement(0));
  CHECK_EQUAL(30, liste.getElement(1));
  CHECK_EQUAL(20, liste.getElement(2));
  CHECK_EQUAL(10, liste.getElement(3));
}
