#include "Image.hpp"

#include <string>
#include <cmath>
#include <iostream>

Image::Image(int largeur, int hauteur) :
  _largeur(largeur),
  _hauteur(hauteur)
{
  if (largeur <= 0 || hauteur <= 0)
    throw std::string("Dimension(s) invalide(s) !");
  _pixels = new int[largeur * hauteur];
}

Image::~Image()
{
  delete [] _pixels;
}

int Image::getLargeur() const { return _largeur; }
int Image::getHauteur() const { return _hauteur; }

const int& Image::getPixel(int i, int j) const
{
  if (i < 0 || j < 0 || i >= _largeur || j >= _hauteur)
    throw std::string("Coordonnées invalides !");

  return _pixels[i + _largeur * j];
}

void Image::setPixel(int i, int j, int couleur)
{
  if (i < 0 || j < 0 || i >= _largeur || j >= _hauteur)
    throw std::string("Coordonnées invalides !");
  
  _pixels[i + _largeur * j] = couleur;
}

void remplir(Image& image)
{
  for (int i = 0; i < image.getLargeur() * image.getHauteur(); i++)
  {
    image.setPixel(i % image.getLargeur(), i / image.getHauteur(),
		   cos(i) * 255);
    // std::cout << image.getPixel(i % image.getLargeur(), i / image.getHauteur())
    // 	      << std::endl;
  }
}

void ecrirePnm(const Image& image, const std::string& nomFichier)
{
  
}
