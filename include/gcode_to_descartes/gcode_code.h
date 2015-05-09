#ifndef GCODE_CODE_H
#define GCODE_CODE_H

#include <vector>

namespace gcode
{


struct Code
{
  enum ModeGroup {MOTION, FEEDRATE} group;
  enum Type {G0, G1, G30} type;

  struct Arg {
    double real;
    char symbol;
  };

  std::vector<Arg> args;
};

}

#endif