#ifndef FIGURE_GEOMETRIQUE
#define FIGURE_GEOMETRIQUE

#include "Couleur.hpp"

class FigureGeometrique
{
public:
  FigureGeometrique(const Couleur&);
  const Couleur& getCouleur() const;
protected:
  Couleur _couleur;
};

#endif
