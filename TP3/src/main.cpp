#include <iostream>
#include "Location.hpp"
#include "Client.hpp"
#include "Produit.hpp"
#include "Magasin.hpp"

int main(int argc, char **argv)
{
  Magasin magasin;
  
  magasin.ajouterClient("Thomas");
  magasin.ajouterClient("Jacqueline");
  magasin.ajouterClient("Paul");
  
  magasin.ajouterProduit("Tomates");
  magasin.ajouterProduit("Haché");
  magasin.ajouterProduit("Pomme");

  magasin.ajouterLocation(0, 2);
  magasin.ajouterLocation(1, 1);
  magasin.ajouterLocation(2, 0);
  
  magasin.afficherClients();
  magasin.afficherProduits();
  magasin.afficherLocations();
  
  return 0;
}
