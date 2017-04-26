#ifndef LISTE_HPP
#define LISTE_HPP

#define NOEUD_INVALIDE -1

struct Noeud
{
  int _valeur;
  Noeud* _suivant;
};

struct Liste
{
  Noeud* _tete;
  
  Liste();
  ~Liste();
  void ajouterDevant(int valeur);
  int getTaille() const;
  int getElement(int indice) const;
};

#endif
