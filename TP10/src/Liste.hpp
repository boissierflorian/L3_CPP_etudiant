#ifndef LISTE_HPP_
#define LISTE_HPP_

#include <cassert>
#include <ostream>

// liste d'entiers avec itérateur
class Liste {
private:
  struct Noeud {
    int _valeur;
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
    
    int& operator*() const {
      return _ptrNoeudCourant->_valeur;
    }
    
    bool operator!=(const iterator & it) const {
      return _ptrNoeudCourant != it._ptrNoeudCourant;
    }

    friend Liste; 
  };

public:
  Liste() : _ptrTete(nullptr) {}
  ~Liste() { clear(); }
  
  void push_front(int a)
  {
    // Modification de la tête
    _ptrTete = new Noeud{a, _ptrTete};
  }

  int& front() const {
    // Si pas de tête que retourner ?
    assert(_ptrTete);
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

std::ostream& operator<<(std::ostream& os, const Liste& l) {
  for (auto it = l.begin(); it != l.end(); ++it)
    os << *it << " ";
  
  return os;
}

#endif
