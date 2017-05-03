#ifndef LISTE_GENERIQUE_HPP
#define LISTE_GENERIQUE_HPP

#include <cassert>
#include <ostream>

template <typename T> 
class ListeGenerique {
private:
  struct Noeud {
    T _valeur;
    struct Noeud* _ptrNoeudSuivant; 
  };

  Noeud* _ptrTete;
public:
  class iterator {

  private:
    Noeud* _ptrNoeudCourant;
    
  public:
    iterator(Noeud* ptrNoeudCourant)
    {
      _ptrNoeudCourant = ptrNoeudCourant;
    }
    
    const iterator & operator++() {
      // On avance dans la liste
      _ptrNoeudCourant = _ptrNoeudCourant->_ptrNoeudSuivant;
      return *this;
    }
    
    T& operator*() const {
      return _ptrNoeudCourant->_valeur;
    }
    
    bool operator!=(const iterator & it) const {
      return _ptrNoeudCourant != it._ptrNoeudCourant;
    }

    friend ListeGenerique; 
  };

public:
  ListeGenerique() : _ptrTete(nullptr) {}
  ~ListeGenerique() { clear(); }
  
  void push_front(T a)
  {
    // Modification de la tête
    _ptrTete = new Noeud{a, _ptrTete};
  }

  T& front() const {
    // Si pas de tête que retourner ?
    return _ptrTete->_valeur;
  }

  void clear() {
    Noeud* suiv;
    
    while (_ptrTete)
    {
      suiv = _ptrTete->_ptrNoeudSuivant;
      delete _ptrTete;
      _ptrTete = suiv;
    }
  }

  bool empty() const {
    return !_ptrTete;
  }

  iterator begin() const {
    return iterator(_ptrTete);
  }

  iterator end() const {
    return iterator(nullptr);
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const ListeGenerique<T>& l) {
  for (auto it = l.begin(); it != l.end(); ++it)
    os << *it << " ";
  
  return os;
}

#endif
