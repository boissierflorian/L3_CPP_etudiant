#ifndef LIGNE_HPP
#define LIGNE_HPP

#include "FigureGeometrique.hpp"
#include "Point.hpp"

#include <gtkmm.h>

class Ligne : public FigureGeometrique
{
public:
  Ligne(const Couleur&, const Point&, const Point&);
  void afficher(const Cairo::RefPtr<Cairo::Context>&) const override;
  const Point& getP0() const;
  const Point& getP1() const;
private:
  Point _p0;
  Point _p1;
};

#endif