/////////////////////////////////////////////////////////////////////////////
//                                  Parser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Parser_h
#define Parser_h

#include <queue>
#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include "Functor.h"


using std::vector;
using std::string;


const string CMD_HELP = "help";
const string CMD_NOT_FOUND = "Invalid command. See available: " + CMD_HELP;


/**
 *  @class CommandProcessor
 *
 *  @brief Stores built-in commands and evaluates string input
 *
 *  A small compiler that will be useful for for client-side
 *  commands, scripting, crafting, or minigame implementation.
 */
class Parser {
public:
    
    Parser();
    
   ~Parser();
    
    // Tokenize and parse input
    string parse(const string &input) const;
    
    
private:
    
};

#endif /* Parser_h */
