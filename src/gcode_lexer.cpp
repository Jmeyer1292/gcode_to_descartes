#include "gcode_lexer.h"
#include "gcode_exception.h"

#include <iostream>
#include <sstream>

gcode::Lexer::Lexer(std::istream& is) 
  : is_(is)
{}

gcode::Token gcode::Lexer::readToken()
{
  std::string buffer;
  char c;
  // Get first character
  while (is_ && (c = is_.get()) == ' ') {}

  if (is_.eof()) return Token(Token::END_FILE, "");

  // First character should be a newline or letter
  if (c == '\n') return Token(Token::END_LINE, "");
  else if (!std::isalpha(c)) {
    std::stringstream ss;
    ss << "Unexpected character '" << c << "' at start of word";
    throw GCodeError(ss.str());
  }
  // we have the letter, now push back onto buffer while the next word is not a letter or eol
  buffer.push_back(c);
  while (is_) {
    char next = is_.peek();
    if (next == '\n' || std::isalpha(next)) {
      return Token(Token::WORD, buffer);
    }
    c = is_.get();
    if (c != ' ' && c != EOF)
      buffer.push_back(c);
  }

  return Token(Token::WORD, buffer);
}
