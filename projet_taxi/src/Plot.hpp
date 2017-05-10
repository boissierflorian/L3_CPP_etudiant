#ifndef PLOT_HPP_
#define PLOT_HPP_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "gnuplot-iostream.h"
#include <glog/logging.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/Connector.h>
#include <string>

////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////
class Plot
{
public:
  virtual ~Plot() = default;
  virtual const std::string plot() = 0;
};

class PlotBrands : public Plot
{
public:
  PlotBrands(){}
  const std::string plot() override;
};

class PlotCalls : public Plot
{
public:
  PlotCalls(){}
  const std::string plot() override;
};

class PlotDrivers : public Plot
{
public:
  PlotDrivers(){}
  const std::string plot() override;
};


#endif
