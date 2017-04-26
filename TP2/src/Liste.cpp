#include "Liste.hpp"

Liste::Liste() :
  _tete(nullptr)
{
  
}

Liste::~Liste()
{
  Noeud* suivant = _tete;

  // Tant que l'élément courant existe
  while (_tete)
  {
    // On mémorise l'élément suivant
    suivant = _tete->_suivant;

    // On supprime la tête
    _tete->_suivant = nullptr;
    delete _tete;

    // On passe à l'élément suivant
    _tete = suivant;
  }
}

void Liste::ajouterDevant(int valeur)
{
  Noeud* noeud = new Noeud();
  noeud->_valeur = valeur;
  
  // Liste vide
  if (!_tete)
  {
    _tete = noeud;
    return;
  }

  // La tête devient le second élément
  noeud->_suivant = _tete;
  _tete = noeud;
}

int Liste::getTaille() const
{
  int taille = 0;
  Noeud* noeud = _tete;

  while(noeud)
  {
    noeud = noeud->_suivant;
    taille++;
  }

  return taille;
}

int Liste::getElement(int indice) const
{
  Noeud* noeud = _tete;

  while (noeud)
  {
    if (indice-- == 0)
      return noeud->_valeur;

    noeud = noeud->_suivant;
  }
  
  return NOEUD_INVALIDE;
}
