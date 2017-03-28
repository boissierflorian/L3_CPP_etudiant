#include <iostream>
#include <vector>

#include "Ligne.hpp"
#include "PolygoneRegulier.hpp"
#include "FigureGeometrique.hpp"

using namespace std;

int main(int argc, char** argv)
{
  Ligne ligne({1, 0, 0}, {0, 0}, {100, 200});
  PolygoneRegulier poly({0, 1, 0}, {100, 200}, 50, 5);
  Ligne ligne2({1, 1, 1}, {10, -10}, {0, 20});

  // Polymorphisme
  vector<FigureGeometrique*> figures;
  figures.push_back(&ligne);
  figures.push_back(&poly);
  figures.push_back(&ligne2);
  
  for (FigureGeometrique* fig : figures)
    fig->afficher();
 
  return 0;
}
