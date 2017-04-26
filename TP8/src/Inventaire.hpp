#ifndef INVENTAIRE_HPP_
#define INVENTAIRE_HPP_

#include "Bouteille.hpp"

#include <iostream>
#include <vector>

// Modèle : inventaire de bouteilles.
struct Inventaire {
    std::vector<Bouteille> _bouteilles;
};

std::istream& operator>>(std::istream& is, Inventaire& i); 
std::ostream& operator<<(std::ostream& os, Inventaire & i);

#endif
