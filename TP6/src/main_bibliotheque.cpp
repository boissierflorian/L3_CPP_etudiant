#include "Bibliotheque.hpp"

int main() {  
  Bibliotheque b;
  b.push_back(Livre("t1","a1",13));
  b.push_back(Livre("t2","a2",37));
  b.push_back(Livre("t0","a0",42));
  b.afficher();
  return 0;
}
