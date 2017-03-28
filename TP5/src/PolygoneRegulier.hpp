#ifndef POLYGONE_REGULIER_HPP
#define POLYGONE_REGULIER_HPP

#include "FigureGeometrique.hpp"
#include "Point.hpp"
#include "Couleur.hpp"

#include <vector>
#include <gtkmm.h>

class PolygoneRegulier : public FigureGeometrique
{
public:
  PolygoneRegulier(const Couleur&, const Point&, int, int);
  ~PolygoneRegulier();
  void afficher(const Cairo::RefPtr<Cairo::Context>&) const override;
  int getNbPoints() const;
  const Point& getPoint(int) const;
private:
  std::vector<Point> _points;
};

#endif
