#ifndef ZONE_DESSIN_HPP
#define ZONE_DESSIN_HPP

#include <gtkmm.h>
#include <vector>
#include <random>
#include <memory>

#include "FigureGeometrique.hpp"

typedef std::unique_ptr<FigureGeometrique> Ptr;

class ZoneDessin : public Gtk::DrawingArea
{
public:
  ZoneDessin();
  ~ZoneDessin();
  void ajouterPolygone(int x, int y);
  void supprimerDernierPolygone();
  void refresh();
protected:
  bool on_expose_event(GdkEventExpose*) override;
  bool gererClic(GdkEventButton*);
private:
  std::vector<Ptr> _figures;
  std::default_random_engine _generateur;
  std::uniform_int_distribution<int> _distRayon;
  std::uniform_int_distribution<int> _distCotes;
};

#endif
