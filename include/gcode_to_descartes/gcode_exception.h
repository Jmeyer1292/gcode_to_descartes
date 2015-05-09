#ifndef GCODE_EXCEPTION_H
#define GCODE_EXCEPTION_H

#include <stdexcept>

namespace gcode
{

class GCodeError : public std::runtime_error
{
public:
  GCodeError(const std::string& what) 
  : std::runtime_error(what) 
  {}
};

}

#endif