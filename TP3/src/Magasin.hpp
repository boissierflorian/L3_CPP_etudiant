#ifndef MAGASIN_HPP
#define MAGASIN_HPP

#include <vector>
#include "Client.hpp"
#include "Produit.hpp"
#include "Location.hpp"

class Magasin
{
public:
  Magasin();
  int nbClients() const;
  void ajouterClient(const std::string& nom);
  void afficherClients() const;
  void supprimerClient(int id);

  int nbProduits() const;
  void ajouterProduit(const std::string& description);
  void afficherProduits() const;
  void supprimerProduit(int id);

  int nbLocations() const;
  void ajouterLocation(int idClient, int idProduit);
  void supprimerLocation(int idClient, int idProduit);
  void afficherLocations() const;
  bool trouverClientDansLocation(int idClient) const;
  std::vector<int> calculerClientsLibres() const;
  bool trouverProduitDansLocation(int idProduit) const;
  std::vector<int> calculerProduitslibres() const;
private:
  std::vector<Client> _clients;
  std::vector<Produit> _produits;
  std::vector<Location> _locations;
  int _idCourantClient;
  int _idCourantProduit;
};

#endif
