#include "Liste.hpp"
#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
  Liste liste;

  liste.ajouterDevant(13);
  liste.ajouterDevant(37);

  int taille = liste.getTaille();

  for (int i = 0; i < taille; i++)
    cout << i << " = " << liste.getElement(i) << endl;
    
  return 0;
}
