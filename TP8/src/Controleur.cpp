#include "Controleur.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Controleur::Controleur(int argc, char ** argv) {
     _vues.push_back(std::make_unique<VueConsole>(argc, argv, *this));
     _vues.push_back(std::make_unique<VueGraphique>(argc, argv, *this));
}

void Controleur::run() {
    for (auto & v : _vues)
        v->run();
}

std::string Controleur::get_texte()
{
  std::ostringstream os;
  os << _inventaire;
  return os.str();
}

void Controleur::chargerInventaire(const std::string& nomFichier)
{
  std::ifstream is(nomFichier);
 
  is >> _inventaire;
  
  for (std::unique_ptr<Vue>& v : _vues)
    v->actualiser();
}
