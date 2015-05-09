#ifndef GCODE_PARSER_H
#define GCODE_PARSER_H

#include "gcode_lexer.h"
#include "gcode_code.h"

namespace gcode
{

class Parser
{
public:
  Parser(Lexer& lexer);
};

}

#endif