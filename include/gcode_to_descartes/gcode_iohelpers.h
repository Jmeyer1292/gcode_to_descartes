#ifndef GCODE_IOHELPERS_H
#define GCODE_IOHELPERS_H

#include <iosfwd>
#include "gcode_lexer.h"
#include "gcode_code.h"

namespace gcode
{
  std::ostream& operator<<(std::ostream& os, const Token& token);
  std::ostream& operator<<(std::ostream& os, const Code& code);
}

#endif