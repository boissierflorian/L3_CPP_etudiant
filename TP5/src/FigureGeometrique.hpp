#ifndef FIGURE_GEOMETRIQUE
#define FIGURE_GEOMETRIQUE

#include "Couleur.hpp"
#include <gtkmm.h>

class FigureGeometrique
{
public:
  FigureGeometrique(const Couleur&);
  virtual ~FigureGeometrique() = default;
  const Couleur& getCouleur() const;
  virtual void afficher(const Cairo::RefPtr<Cairo::Context>&) const = 0;
protected:
  Couleur _couleur;
};

#endif
