#include "Livre.hpp"
#include <vector>
#include <iostream>

Livre::Livre() { }
Livre::Livre(const std::string& titre, const std::string& auteur, int annee) :
_annee(annee)
{
  if (titre.find("\n") != std::string::npos)
  {
    throw std::string("erreur : titre non valide ('\n' non autorisé)");
  }
  
  if (titre.find(";") != std::string::npos)
  {
    throw std::string("erreur : titre non valide (';' non autorisé)");
  }
  
  if (auteur.find("\n") != std::string::npos)
  {
    throw std::string("erreur : auteur non valide ('\n' non autorisé)");
  }
  
  if (auteur.find(";") != std::string::npos)
  {
    throw std::string("erreur : auteur non valide (';' non autorisé)");
  }
  
  _titre = titre;
  _auteur = auteur;
}

bool Livre::operator <(const Livre& livre)
{
  if (this->_auteur == livre._auteur)
    return this->_titre < livre._titre;
  
  return this->_auteur < livre._auteur;
}

bool Livre::operator <<(std::string& donnees)
{
  std::cout << "Saisir un livre format(<titre>;<auteur>;<annee>):\n";
  std::getline(std::cin, donnees);
  std::vector<std::string> tokens = split(std::stringstream(donnees));

  if (tokens.size() < 3)
    return false;

  _titre = tokens[0];
  _auteur = tokens[1];
  _annee = std::stoi(tokens[2]);
  
  return true;
}


const std::string& Livre::getTitre() const { return _titre; }
const std::string& Livre::getAuteur() const { return _auteur; }
int Livre::getAnnee() const { return _annee; }

void Livre::setTitre(const std::string& titre)
{
  _titre = titre;
}

void Livre::setAuteur(const std::string& auteur)
{
  _auteur = auteur;
}

void Livre::setAnnee(int annee)
{
  _annee = annee;
}

// Objectif: analyser la chaîne de caractères
// de type: titre;auteur;année
// Il est possible de passer par la STL
bool operator >>(std::stringstream& stream, Livre& livre)
{
  std::vector<std::string> tokens = split(stream);
  
  // Format des données invalide
  if (tokens.size() < 3)
  {
    std::cerr << "Size: " << tokens.size() << std::endl;
    return false;
  }

  livre.setTitre(tokens[0]);
  livre.setAuteur(tokens[1]);
  // la flemme de check
  livre.setAnnee(std::stoi(tokens[2])); 
  
  return true;
}

void operator<<(std::stringstream& stream, const Livre& livre)
{
  stream << livre.getTitre() << ";" << livre.getAuteur() << ";"
	 << livre.getAnnee();
}

bool operator ==(const Livre& a, const Livre& b)
{
  return (a.getTitre() == b.getTitre()) &&
    (a.getAuteur() == b.getAuteur()) &&
    (a.getAnnee() == b.getAnnee());
}

std::istream& operator>>(std::istream& is, Livre& livre)
{
  is >> livre._titre;
  is >> livre._auteur;
  is >> livre._annee;

  livre.afficher();
  return is;
}

std::ostream& operator<<(std::ostream& os, const Livre& livre)
{
  return os << livre._titre << std::endl << livre._auteur << std::endl
	    << livre._annee << std::endl;
}

std::vector<std::string> split(const std::stringstream& stream)
{
  // Contient les données extraites
  std::vector<std::string> tokens;

  // Travaille avec une copie de la chaîne
  std::string donnees = stream.str();

  // La donnée courante
  std::stringstream sstream;

  // Parcours des données
  for(auto iter = donnees.begin(); iter != donnees.end(); iter++)
  {
    // Ajoute chaque caractère à la donnée courante
    if (*iter != ';')
      sstream << *iter;

    // On arrive sur un délimiteur/la fin
    if (*iter == ';' or iter == donnees.end() - 1)
    {
      // On stocke la donnée
      tokens.push_back(sstream.str());
      // Puis on reset la donnée courante
      sstream.str("");
    }
  }

  return tokens;
}

void Livre::afficher() const
{
  std::cout << "(" << _titre << "," << _auteur << ","
	    << _annee << ")" << std::endl;
}
