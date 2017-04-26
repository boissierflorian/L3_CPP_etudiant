#include "Inventaire.hpp"

#include <locale>

std::istream& operator >>(std::istream& is, Inventaire& i) {
	Bouteille b;

	while (is >> b)
	  i._bouteilles.push_back(b);
	
	return is;
}


std::ostream & operator<<(std::ostream & os, Inventaire & i)
{
  std::locale vieuxLoc = std::locale::global(std::locale("fr_FR.UTF-8"));

  for (Bouteille& b : i._bouteilles)
    os << b;

  std::locale::global(vieuxLoc);
  
  return os;
}
