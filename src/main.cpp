#include <iostream>
#include <fstream>

#include "gcode_lexer.h"
#include "gcode_iohelpers.h"
// scanner reads lines
// lexer takes lines and produces tokens (words)
// parser creates sequences of commands for a given line


int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cerr << "usage: ./lexer_test <gcode_file>\n";
    return 1;
  }
  
  std::ifstream ifile (argv[1]);

  if (!ifile) 
  {
    std::cerr << "Could not read from file";
    return 1;
  } 

  gcode::Lexer lexer {ifile};

  while (true) {
    gcode::Token t = lexer.readToken();
    if (t.type == gcode::Token::END_FILE) break;
    std::cout << t << std::endl;
  }
  
}