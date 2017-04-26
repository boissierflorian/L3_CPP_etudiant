#ifndef PRODUIT_HPP
#define PRODUIT_HPP

#include <string>

class Produit
{
public:
  Produit(int id, const std::string& description);
  int getId() const;
  const std::string& getDescription() const;
  void afficherProduit() const;
private:
  int _id;
  std::string _description;
};

#endif
