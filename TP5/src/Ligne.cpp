#include "Ligne.hpp"

#include <iostream>

using namespace std;

Ligne::Ligne(const Couleur& couleur, const Point& p0, const Point& p1) :
  FigureGeometrique(couleur),
  _p0(p0),
  _p1(p1) { }

void Ligne::afficher(const Cairo::RefPtr<Cairo::Context>& context) const
{
  cout << "Ligne " << _couleur._r << "_" << _couleur._g << "_"
       << _couleur._b << " " << _p0._x << "_" << _p0._y << " "
       << _p1._x << "_" << _p1._y << endl;

  context->set_source_rgb(_couleur._r, _couleur._g, _couleur._b);
  context->move_to(_p0._x, _p0._y);
  context->line_to(_p1._x, _p1._y);
}

const Point& Ligne::getP0() const { return _p0; }
const Point& Ligne::getP1() const { return _p1; }
