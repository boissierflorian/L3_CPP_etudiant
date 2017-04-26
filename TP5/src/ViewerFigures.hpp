#ifndef VIEWER_FIGURES_HPP
#define VIEWER_FIGURES_HPP

#include <gtkmm.h>

#include "ZoneDessin.hpp"

class ViewerFigures
{
public:
  ViewerFigures(int argc, char** argv);
  void run();
private:
  Gtk::Main _kit;
  Gtk::Window _window;
  ZoneDessin _zone;
};

#endif
