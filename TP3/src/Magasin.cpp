#include "Magasin.hpp"
#include <utility>
#include <algorithm>

Magasin::Magasin() :
  _idCourantClient(0),
  _idCourantProduit(0)
{
}

void Magasin::ajouterClient(const std::string& nom)
{
  Client c{_idCourantClient++, nom};
  _clients.push_back(c);
}

void Magasin::ajouterProduit(const std::string& description)
{
  Produit p{_idCourantProduit++, description};
  _produits.push_back(p);
}

void Magasin::ajouterLocation(int idClient,int idProduit)
{
  for (Location& l : _locations)
    if (l._idClient == idClient && l._idProduit == idProduit)
      throw std::string("Location existante !");
  
  Location loc{idClient, idProduit};
  _locations.push_back(loc);
}

void Magasin::supprimerClient(int id)
{
  for (unsigned i = 0; i < _clients.size(); i++)
  {
    Client& c = _clients[i];

    if (c.getId() == id)
    {
      std::swap(_clients[i], _clients.back());
      _clients.pop_back();
      return;
    }
  }

  throw std::string("Ce client n'existe pas !");
}

void Magasin::supprimerProduit(int id)
{
  for (unsigned i = 0; i < _produits.size(); i++)
  {
    Produit& p = _produits[i];

    if (p.getId() == id)
    {
      std::swap(_produits[i], _produits.back());
      _produits.pop_back();
      return;
    }
  }

  throw std::string("Ce produit n'existe pas !");
}

void Magasin::supprimerLocation(int idClient, int idProduit)
{
  for (unsigned i = 0; i < _locations.size(); i++)
  {
    Location& l = _locations[i];

    if (l._idClient == idClient && l._idProduit == idProduit)
    {
      std::swap(_locations[i], _locations.back());
      _locations.pop_back();
      return;
    }
  }

  throw std::string("Location inexistante !");
}
  
void Magasin::afficherClients() const
{
  for (Client client : _clients)
    client.afficherClient();
}

void Magasin::afficherProduits() const
{
  for (Produit produit : _produits)
    produit.afficherProduit();
}

void Magasin::afficherLocations() const
{
  for (Location l : _locations)
    l.afficherLocation();
}

bool Magasin::trouverClientDansLocation(int idClient) const
{
  for (Client c : _clients)
    if (c.getId() == idClient)
      return true;

  return false;
}

bool Magasin::trouverProduitDansLocation(int idProduit) const
{
  for (Produit p : _produits)
    if (p.getId() == idProduit)
      return true;

  return false;
}

std::vector<int> Magasin::calculerClientsLibres() const
{
  std::vector<int> libres;
  
  for (Client c : _clients)
    if (!trouverClientDansLocation(c.getId()))
      libres.push_back(c.getId());

  return libres;
}

std::vector<int> Magasin::calculerProduitslibres() const
{
  std::vector<int> libres;
  
  for (Produit p : _produits)
    if (!trouverProduitDansLocation(p.getId()))
      libres.push_back(p.getId());

  return libres;
}

int Magasin::nbProduits() const { return _produits.size(); }
int Magasin::nbClients() const { return _clients.size(); }
int Magasin::nbLocations() const { return _locations.size(); }
