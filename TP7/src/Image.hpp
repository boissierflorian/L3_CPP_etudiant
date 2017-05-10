#ifndef IMAGE_HPP
#define IMAGE_HPP

class Image
{
public:
  Image(int largeur, int hauteur);
  ~Image();

  int getLargeur() const;
  int getHauteur() const;
  const int& getPixel(int i, int j) const;
  void setPixel(int i, int j, int couleur);
private:
  int _largeur;
  int _hauteur;
  int* _pixels;
};

void remplir(Image& image);
void ecrirePnm(const Image& image, const std::string& nomFichier);

#endif
