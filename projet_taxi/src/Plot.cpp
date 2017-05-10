////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Plot.hpp"

using Poco::Data::Keywords::into;
using Poco::Data::Keywords::range;
using Poco::Data::Statement;
using Poco::Data::Session;

using namespace std;


////////////////////////////////////////////////////////////
const string PlotBrands::plot()
{
  // SQLite connector
  Poco::Data::SQLite::Connector::registerConnector();

  // Taxi database session 
  Poco::Data::Session session("SQLite", "data.db");

  vector<pair<string, int>> data;
  string brand;
  int count;

  std::locale oldLoc = std::locale::global(std::locale("C"));
  Statement select(session);
  select << "select BRAND, COUNT(*) \
        from taxi t inner join trip tr ON t.id=tr.taxi GROUP BY BRAND",
    into(brand), into(count), range(0, 1); 
  while (not select.done()) {
    select.execute();
    data.push_back(make_pair(brand, count));
  }
  std::locale::global(oldLoc);
  LOG(INFO) << data.size() << " row(s) read\n";
  LOG(INFO) << "first row: " << data.front().first << " " 
	    << data.front().second << endl;

  // plot data
  Gnuplot gp;
  gp << "set output 'out_brand.png' \n";
  gp << "set terminal png size 800,600 \n";
  gp << "set style fill solid border -1 \n";
  gp << "set grid ytics \n";
  gp << "set boxwidth 0.8 \n";
  gp << "set xtics rotate by -45 \n";
  gp << "plot " << gp.file1d(data, "out_brand.csv") 
     << " using 2:xtic(1) lc rgb 'red' with boxes notitle \n";

  return "out_brand.png";
}


////////////////////////////////////////////////////////////
const string PlotCalls::plot()
{
  // SQLite connector
  Poco::Data::SQLite::Connector::registerConnector();

  // Taxi database session 
  Poco::Data::Session session("SQLite", "data.db");

  vector<pair<string, int>> data;
  string desc;
  int count;

  std::locale oldLoc = std::locale::global(std::locale("C"));
  Statement select(session);
  select << "select DESC, COUNT(*) \
        from call c inner join trip tr ON c.id=tr.call GROUP BY DESC",
    into(desc), into(count), range(0, 1); 
  while (not select.done()) {
    select.execute();
    data.push_back(make_pair(desc, count));
  }
  std::locale::global(oldLoc);
  LOG(INFO) << data.size() << " row(s) read\n";
  LOG(INFO) << "first row: " << data.front().first << " " 
	    << data.front().second << endl;

  // plot data
  Gnuplot gp;
  gp << "set output 'out_calls.png' \n";
  gp << "set terminal png size 800,600 \n";
  gp << "set style fill solid border -1 \n";
  gp << "set grid ytics \n";
  gp << "set boxwidth 0.8 \n";
  gp << "set xtics rotate by -45 \n";
  gp << "plot " << gp.file1d(data, "out_calls.csv") 
     << " using 2:xtic(1) lc rgb 'green' with boxes notitle \n";

  return "out_calls.png";
}


////////////////////////////////////////////////////////////
const string PlotDrivers::plot()
{
  // SQLite connector
  Poco::Data::SQLite::Connector::registerConnector();

  // Taxi database session 
  Poco::Data::Session session("SQLite", "data.db");

  vector<pair<string, int>> data;
  string firstname, lastname;
  int count;

  std::locale oldLoc = std::locale::global(std::locale("C"));
  Statement select(session);
  select << "select FIRSTNAME, LASTNAME, COUNT(*) \
        from driver d inner join trip tr ON d.id=tr.driver GROUP BY LASTNAME limit 20",
    into(firstname), into(lastname), into(count), range(0, 1); 
  while (not select.done()) {
    select.execute();
    data.push_back(make_pair(firstname + " " + lastname + ";", count));
  }
  std::locale::global(oldLoc);
  LOG(INFO) << data.size() << " row(s) read\n";
  LOG(INFO) << "first row: " << data.front().first << " " 
	    << data.front().second << endl;

  // plot data
  Gnuplot gp;
  gp << "set output 'out_drivers.png' \n";
  gp << "set datafile separator ';'\n";
  gp << "set terminal png size 800,600 \n";
  gp << "set style fill solid border -1 \n";
  gp << "set grid ytics \n";
  gp << "set boxwidth 0.8 \n";
  gp << "set xtics rotate by -45 \n";
  gp << "plot " << gp.file1d(data, "out_drivers.csv") 
     << " using 2:xtic(1) lc rgb 'green' with boxes notitle \n";

  return "out_drivers.png";
}
