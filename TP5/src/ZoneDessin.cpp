#include "ZoneDessin.hpp"
#include "Ligne.hpp"
#include "PolygoneRegulier.hpp"

#include <iostream>

ZoneDessin::ZoneDessin() :
  _distRayon(10, 90),
  _distCotes(3, 12)
{
  Ptr poly(new PolygoneRegulier({0, 0.75, 0}, {375, 120}, 100, 5));
  Ptr poly2(new PolygoneRegulier({0, 0.75, 0}, {320, 300}, 60, 6));
  Ptr poly3(new PolygoneRegulier({0, 0.75, 0}, {460, 300}, 30, 6));
  Ptr poly4(new PolygoneRegulier({0, 0.75, 0}, {80, 100}, 50, 4));
  Ptr poly5(new PolygoneRegulier({0, 0.75, 0}, {120, 320}, 80, 4));

  _figures.push_back(std::move(poly));
  _figures.push_back(std::move(poly2));
  _figures.push_back(std::move(poly3));
  _figures.push_back(std::move(poly4));
  _figures.push_back(std::move(poly5));
  
  add_events(Gdk::EventMask::BUTTON_PRESS_MASK);
  signal_button_press_event().connect(sigc::mem_fun(*this,
				      &ZoneDessin::gererClic));
}

ZoneDessin::~ZoneDessin()
{
  //for (FigureGeometrique* fig : _figures)
  //  delete fig;
}

bool ZoneDessin::on_expose_event(GdkEventExpose* event)
{
  // Récupère la fenêtre associée à la DrawingArea
  Glib::RefPtr<Gdk::Window> window = get_window();
  
  if (window)
  {
    // Recupère les dimensions de la fenêtre
    int width = window->get_width();
    int height = window->get_height();

    // Décalage par rapport aux bords de la fenêtre
    int offset = 10;
 
    // Contexte du dessin
    Cairo::RefPtr<Cairo::Context> context =
      window->create_cairo_context();

    context->set_source_rgb(1.0, 0.0, 0.0);
    context->set_line_width(5.0);
    
    context->move_to(offset, offset);
    context->line_to(width - offset, offset);

    context->move_to(width - offset, offset);
    context->line_to(width - offset, height - offset);

    context->move_to(width - offset, height - offset);
    context->line_to(offset, height - offset);

    context->move_to(offset, height - offset);
    context->line_to(offset, offset);

    context->stroke();
    
    for (const Ptr& fig : _figures)
      fig->afficher(context);
  }
  
  return true;
}

bool ZoneDessin::gererClic(GdkEventButton* event)
{
  if (event->button == 1)
    ajouterPolygone((int) event->x, (int) event->y);
  else if (event->button == 3) {
    supprimerDernierPolygone();
  }

  if (event->button == 1 || event->button == 3)
    refresh();
  
  return true;
}

void ZoneDessin::ajouterPolygone(int x, int y)
{
  Ptr poly(new PolygoneRegulier({0, 1, 0}, {x, y}, _distRayon(_generateur),
				_distCotes(_generateur)));
  // Move permet de ne pas copier le poly
  // on passe directement la vraie valeur
  _figures.push_back(std::move(poly)); 
}

void ZoneDessin::supprimerDernierPolygone()
{
  if (_figures.size() == 0)
    return;

  // L'unique pointer se retrouve dans la "nature"
  // Il sera donc automatiquement désalloué !
  _figures.pop_back();
}

void ZoneDessin::refresh()
{
  // Récupère la fenêtre associée à la DrawingArea
  Glib::RefPtr<Gdk::Window> window = get_window();
  
  if (window)
    window->invalidate(true);
}
