#include "PolygoneRegulier.hpp"

#include <cmath>
#include <iostream>

using namespace std;

PolygoneRegulier::PolygoneRegulier(const Couleur& couleur, const Point& centre,
				   int rayon, int nbCotes) :
  FigureGeometrique(couleur), _points(nbCotes)
{
  // En radians
  // Équivalent à 360 / nbPoints
  double ang = double (2 * M_PI) / nbCotes;

  for (int i = 0; i < nbCotes; i++)
  {
    // cos(theta) nous donne x
    // sin(theta) nous donne y
    // On se place sur le centre d'origine
    // Et on met à l'échelle avec le rayon car cos et sin
    // Nous donne les coordonnées sur le cercle trigo de rayon 1 !
    int x = centre._x + cos(i * ang) * rayon;
    int y = centre._y + sin(i * ang) * rayon;
    _points[i]= {x, y};
  }
}

PolygoneRegulier::~PolygoneRegulier()
{
}

void PolygoneRegulier::afficher(const Cairo::RefPtr<Cairo::Context>& context)
  const
{
  // Partie graphique
  // TODO: Vérifier si le point existe normalement oui..
  context->set_source_rgb(_couleur._r, _couleur._g, _couleur._b);
  
  for (unsigned i = 0; i < _points.size() - 1; i++)
  {
    Point courant = _points[i];
    Point suivant = _points[i + 1];
    context->move_to(courant._x, courant._y);
    context->line_to(suivant._x, suivant._y);
    context->stroke();
  }

  Point start = _points[0];
  Point last = _points[_points.size() - 1];
 
  context->move_to(start._x, start._y);
  context->line_to(last._x, last._y);
  
  context->stroke();
  
  // Partie console
  cout << "PolygoneRegulier " << _couleur._r << "_" << _couleur._g << "_"
       << _couleur._b << " ";
  
  for (unsigned i = 0; i < _points.size(); i++)
  {
    Point p = _points[i];
    cout << p._x << "_" << p._y << " ";
  }

  cout << endl;
}

int PolygoneRegulier::getNbPoints() const
{
  return _points.size();
}

const Point& PolygoneRegulier::getPoint(int indice) const
{
  return _points[indice];
}
