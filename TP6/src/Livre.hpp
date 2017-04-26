#ifndef LIVRE_HPP
#define LIVRE_HPP

// Headers
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

class Livre
{
public:
  Livre();
  Livre(const std::string& titre, const std::string& auteur, int annee);
  const std::string& getTitre() const;
  const std::string& getAuteur() const;
  int getAnnee() const;
  bool operator <(const Livre& livre);
  bool operator <<(std::string& donnees);
  void setTitre(const std::string& titre);
  void setAuteur(const std::string& auteur);
  void setAnnee(int annee);
  void afficher() const;
  
  friend std::istream& operator>>(std::istream& is, Livre& livre);
  friend std::ostream& operator<<(std::ostream& os, const Livre& livre);

private: 
  std::string _titre;
  std::string _auteur;
  int _annee;
};

bool operator ==(const Livre&, const Livre&);
bool operator >>(std::stringstream&, Livre&);
void operator <<(std::stringstream&, const Livre&);

std::vector<std::string> split(const std::stringstream&);


#endif
