#ifndef GCODE_LEXER_H
#define GCODE_LEXER_H

#include <string>
#include <iosfwd>

namespace gcode
{
  struct Token
  {
    enum Type {END_FILE, END_LINE, WORD };
    
    Token(Type type, const std::string& text)
      : text(text)
      , type(type)
    {}
    
    std::string text;
    Type type;
  };

  class Lexer
  {
  public:
    explicit Lexer(std::istream& is);

    /**
     * Reads the next gcode token from the input stream
     * @return a token. Possibly returns END_FILE token
     *         if the file is done.
     */
    Token readToken();
  private:
    std::istream& is_;
  };

} // gcode

#endif