#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client
{
public:
  Client(int id, const std::string& nom);
  int getId() const;
  const std::string& getNom() const;
  void afficherClient() const;
private:
  int _id;
  std::string _nom;
};

#endif
