#include "vecteur3.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void afficher(const Vecteur3& v)
{
  cout << "(" << v._x << ", " << v._y << "," << v._z << ")" << endl; 
}

float produitScalaire(const Vecteur3& v, const Vecteur3& t)
{
  return v._x * t._x + v._y * t._y + v._z * t._z;
}

float addition(const Vecteur3& v, const Vecteur3& t)
{
  return v._x + t._x + v._y + t._y + v._z + t._z;
}

void Vecteur3::afficher()
{
  cout << "(" << _x << ", " << _y << "," << _z << ")" << endl; 
}

double Vecteur3::norme() const
{
  return sqrt((_x * _x) + (_y * _y) + (_z * _z));
}
