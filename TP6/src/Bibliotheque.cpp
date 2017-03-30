#include "Bibliotheque.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

bool triAuteurTitre(Livre& l1, Livre& l2)
{
  return l1 < l2;
}

void Bibliotheque::afficher() const
{
  for (unsigned i = 0; i < size(); i++)
    ((*this)[i]).afficher();
}

void Bibliotheque::trierParAuteurEtTitre()
{
  std::sort(begin(), end(), triAuteurTitre);
}

void Bibliotheque::trierParAnnee()
{
  auto tri = [] (Livre& l1, Livre& l2) { return l1.getAnnee() < l2.getAnnee(); };

  std::sort(begin(), end(), tri);
}

void Bibliotheque::lireFichier(const std::string& nomFichier)
{
  std::ifstream is(nomFichier);

  // Fichier inexistant
  if (!is.is_open())
    throw std::string("erreur : lecture du fichier impossible");

  Livre livre;

  while (is >> livre)
    push_back(Livre(livre.getTitre(), livre.getAuteur(), livre.getAnnee()));
}

void Bibliotheque::ecrireFichier(const std::string& nomFichier) const
{
  std::ofstream os(nomFichier);

  // Vérification de l'existance du fichier
  if (!os)
    throw std::string("Fichier inexistant: " + nomFichier);

  // Ecriture de la bibliothèque
  for (const Livre& livre : *this)
    os << livre;
}
