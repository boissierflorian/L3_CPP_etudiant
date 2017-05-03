#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>
#include <ostream>

struct Personne {
  std::string _nom;
  int _age;
};

std::ostream& operator<<(std::ostream& os, const Personne& p)
{
  return os << "{" << p._nom << " " << p._age << "} ";
}

#endif
