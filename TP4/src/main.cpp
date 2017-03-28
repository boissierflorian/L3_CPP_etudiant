#include <iostream>

#include "Ligne.hpp"

int main(int argc, char** argv)
{
  Ligne ligne({1, 0, 0}, {0, 0}, {100, 200});
  ligne.afficher();
  
  return 0;
}
