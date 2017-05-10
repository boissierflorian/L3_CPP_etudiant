////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "GuiWindow.hpp"
#include "gnuplot-iostream.h"
#include "Plot.hpp"
#include <glog/logging.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>

using Poco::Data::Keywords::into;
using Poco::Data::Keywords::range;
using Poco::Data::Statement;
using Poco::Data::Session;

using namespace std;

////////////////////////////////////////////////////////////
GuiWindow::GuiWindow(int argc, char ** argv) : _kit(argc, argv) {
  Gtk::HBox* ptrHBox = Gtk::manage(new Gtk::HBox);   // Horizontal layout
  ptrHBox->pack_start(_notebook, Gtk::PACK_SHRINK);   // Add notebook
  todoPlot();

  // Config panel
  Gtk::VBox* ptrVBox = Gtk::manage(new Gtk::VBox);   
  ptrHBox->pack_start(*ptrVBox);

  // Quit button
  Gtk::Button* ptrButtonQuit 
    = Gtk::manage(new Gtk::Button("  Quit  "));
  ptrVBox->pack_start(*ptrButtonQuit, Gtk::PACK_SHRINK);
  // Update button
  Gtk::Button* ptrButtonUpdate  = Gtk::manage(new Gtk::Button("  Update  "));
  ptrVBox->pack_start(*ptrButtonUpdate, Gtk::PACK_SHRINK);
  // Signals
  ptrButtonQuit->signal_clicked().connect(sigc::ptr_fun(&Gtk::Main::quit));
  ptrButtonUpdate->signal_clicked().connect(sigc::mem_fun(*this, &GuiWindow::update));
  
  // Notebook pages
  GuiImage* image  = Gtk::manage(new GuiImage(new PlotBrands()));
  GuiImage* image2 = Gtk::manage(new GuiImage(new PlotCalls()));
  GuiImage* image3 = Gtk::manage(new GuiImage(new PlotDrivers()));
  
  _notebook.append_page(*image);
  _notebook.append_page(*image2);
  _notebook.append_page(*image3);
  
  // main window
  _window.add(*ptrHBox);
  _window.show_all();
}


////////////////////////////////////////////////////////////
void GuiWindow::run()
{
    _kit.run(_window);
}


////////////////////////////////////////////////////////////
void GuiWindow::todoPlot() {
    // SQLite connector
    Poco::Data::SQLite::Connector::registerConnector();

    // Taxi database session 
    Poco::Data::Session session("SQLite", "data.db");

    vector<pair<string,double>> data;
    string stationName;
    double stationY;

    std::locale oldLoc = std::locale::global(std::locale("C"));
    Statement select(session);
    select << "select name, y \
        from station \
        limit 20",
           into(stationName), into(stationY), range(0, 1); 
    while (not select.done()) {
        select.execute();
        data.push_back(make_pair(stationName, stationY));
    }
    std::locale::global(oldLoc);
    LOG(INFO) << data.size() << " row(s) read\n";
    LOG(INFO) << "first row: " << data.front().first << " " 
        << data.front().second << endl;

    // plot data
    Gnuplot gp;
    gp << "set output 'out_todo.png' \n";
    gp << "set terminal png size 800,600 \n";
    gp << "set style fill solid border -1 \n";
    gp << "set grid ytics \n";
    gp << "set boxwidth 0.8 \n";
    gp << "set xtics rotate by -45 \n";
    gp << "plot " << gp.file1d(data, "out_todo.csv") 
        << " using 2:xtic(1) lc rgb 'green' with boxes notitle \n";
}


////////////////////////////////////////////////////////////
void GuiWindow::update()
{
  // for (GuiImage* image : _plots)
  //   image->update();
}
