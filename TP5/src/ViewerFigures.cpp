#include "ViewerFigures.hpp"

ViewerFigures::ViewerFigures(int argc, char** argv) :
  _kit(argc, argv)
{
  if (argc > 1)
    _window.set_title(argv[1]);
  else
    _window.set_title("Une fenêtre");

  _window.set_default_size(640, 480);
  _window.set_position(Gtk::WIN_POS_CENTER_ALWAYS);

  _window.add(_zone);
}

void ViewerFigures::run()
{
  _window.show_all();
  _kit.run(_window);
}
