#include <iostream>
#include <algorithm>

#include "Liste.hpp"
#include "ListeGenerique.hpp"
#include "Personne.hpp"

int main() {
  // Version classique
  Liste l1;
  l1.push_front(37);
  l1.push_front(13);
  std::cout << l1 << std::endl;

  // Version générique
  ListeGenerique<float> gen;
  gen.push_front(10.f);
  gen.push_front(10.f);
  gen.push_front(9.8f);
  gen.push_front(3.14f); 
  std::cout << gen << std::endl;

  ListeGenerique<bool> gen_b;
  gen_b.push_front(false);
  gen_b.push_front(true);
  gen_b.push_front(false);
  gen_b.push_front(false);
  
  std::cout << gen_b << std::endl;

  // Liste de personnes
  ListeGenerique<Personne> lp;
  lp.push_front(Personne{"Florian", 20});
  lp.push_front(Personne{"Mike", 19});
  lp.push_front(Personne{"Jeanne", 18});

  //std::cout << lp << std::endl;

  // STL
  std::for_each(lp.begin(), lp.end(), [&](Personne& p){ std::cout << p << std::endl;});

  // Marche pas
  // int majeurs = std::count_if(lp.begin(), lp.end(), [&](Personne& p) { return p._age > 17;});
  // std::cout << "Nombre de majeurs: " << majeurs << std::endl;
  
  return 0;
}
