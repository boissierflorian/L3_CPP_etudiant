#ifndef GUI_WINDOW_HPP_
#define GUI_WINDOW_HPP_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <gtkmm.h>
#include <gtkmm/notebook.h>
#include <gtkmm/spinbutton.h>
#include <memory>
#include <vector>
#include "GuiImage.hpp"

////////////////////////////////////////////////////////////
// GUI Wrapper
////////////////////////////////////////////////////////////
class GuiWindow {
public:
  ////////////////////////////////////////////////////////////
  // \brief Constructeur
  //
  ////////////////////////////////////////////////////////////
  GuiWindow(int argc, char ** argv);

  ////////////////////////////////////////////////////////////
  // \brief Lance la boucle évènementielle de la fenêtre principale
  //
  ////////////////////////////////////////////////////////////
  void run();

  ////////////////////////////////////////////////////////////
  // \brief Mise à jour du graphe en fonction des spin buttons
  //
  ////////////////////////////////////////////////////////////
  void update();
  
  // TODO
  void todoPlot();
private:
  
  ////////////////////////////////////////////////////////////
  // Member data
  //////////////////////////////////////////////////////////// 
  Gtk::Main _kit;                   ///< Gtk app
  Gtk::Window _window;              ///< Main Window
  std::vector<std::unique_ptr<GuiImage>> _plots;     ///< Plots
  Gtk::Notebook _notebook;          
  Gtk::SpinButton _spin_timestamp1; ///< Borne inférieure
  Gtk::SpinButton _spin_timestamp2; ///< Borne supérieure
  Gtk::SpinButton _spin_nb_drivers;
  Gtk::SpinButton _spin_time_bins;
};

#endif
