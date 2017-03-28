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

  for (unsigned i = 0; i < nbCotes; i++)
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

void PolygoneRegulier::afficher() const
{
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
