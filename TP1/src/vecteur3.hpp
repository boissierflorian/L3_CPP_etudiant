#ifndef VECTEUR3_HPP
#define VECTEUR3_HPP

struct Vecteur3
{
  float _x, _y, _z;
  
  void afficher();
  double norme() const;
};

void afficher(const Vecteur3&);
float produitScalaire(const Vecteur3&, const Vecteur3&);
float addition(const Vecteur3&, const Vecteur3&);

#endif
