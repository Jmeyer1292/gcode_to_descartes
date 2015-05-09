#include "gcode_iohelpers.h"
#include <iostream>

std::ostream& gcode::operator<<(std::ostream& os, const gcode::Token& token)
{
  os << "Token(";
  switch (token.type)
  {
    case Token::WORD:
    os << "WORD): '" << token.text <<"'"; break;

    case Token::END_LINE:
    os << "EOL)"; break;

    case Token::END_FILE:
    os << "EOF)"; break;
  }

  return os;
}