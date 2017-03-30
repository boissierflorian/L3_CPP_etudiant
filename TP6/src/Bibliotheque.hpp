#ifndef BIBLIOTHEQUE_HPP
#define BIBLIOTHEQUE_HPP

#include <vector>
#include <string>
#include "Livre.hpp"

class Bibliotheque : public std::vector<Livre>
{
public:
  void afficher() const;
  void trierParAuteurEtTitre();
  void trierParAnnee();
  void lireFichier(const std::string& nomFichier);
  void ecrireFichier(const std::string& nomFichier) const;
};

bool triAuteurTitre(Livre&, Livre&);

#endif
