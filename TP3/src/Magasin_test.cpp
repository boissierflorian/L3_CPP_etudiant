#include <CppUTest/CommandLineTestRunner.h>

#include "Client.hpp"
#include "Produit.hpp"
#include "Location.hpp"
#include "Magasin.hpp"

#include <string>

TEST_GROUP(GroupMagasin) { };

TEST(GroupMagasin, Magasin_test1) 
{
  Magasin magasin;
  CHECK_EQUAL(0, magasin.nbClients());
  magasin.ajouterClient("Tom");
  magasin.ajouterClient("Tina");
  CHECK_EQUAL(2, magasin.nbClients());
  magasin.supprimerClient(0);
  magasin.supprimerClient(1);
  CHECK_EQUAL(0, magasin.nbClients());
}

TEST(GroupMagasin, Magasin_test2) 
{
  Magasin magasin;
  CHECK_EQUAL(0, magasin.nbProduits());
  magasin.ajouterProduit("Tomates");
  magasin.ajouterProduit("Glaces");
  CHECK_EQUAL(2, magasin.nbProduits());
  magasin.supprimerProduit(0);
  magasin.supprimerProduit(1);
  CHECK_EQUAL(0, magasin.nbProduits());
}

TEST(GroupMagasin, Magasin_test3) 
{
  Magasin magasin;
  magasin.ajouterProduit("Tomate");
  magasin.ajouterProduit("Patate");
  magasin.ajouterClient("Tom");
  magasin.ajouterClient("Marc");
  magasin.ajouterLocation(0, 1); // Tom & Patate
  magasin.ajouterLocation(1, 0); // Marc & Tomate
  CHECK_EQUAL(2, magasin.nbLocations());
  magasin.supprimerLocation(0, 1);
  magasin.supprimerLocation(1, 0);
  CHECK_EQUAL(0, magasin.nbLocations());
}

TEST(GroupMagasin, Magasin_test4) 
{
  Magasin magasin;
  
  magasin.ajouterProduit("Tomate");
  magasin.ajouterProduit("Patate");
  magasin.ajouterClient("Tom");
  magasin.ajouterClient("Marc");
  magasin.ajouterLocation(0, 1);

  CHECK_THROWS(std::string, magasin.supprimerClient(-1));
  CHECK_THROWS(std::string, magasin.supprimerClient(2));
  CHECK_THROWS(std::string, magasin.supprimerProduit(-1));
  CHECK_THROWS(std::string, magasin.supprimerProduit(2));
  CHECK_THROWS(std::string, magasin.supprimerLocation(-1,0));
}
