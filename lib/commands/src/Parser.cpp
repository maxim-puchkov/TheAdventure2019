/////////////////////////////////////////////////////////////////////////////
//                                  Parser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Parser.h"

Parser::Parser()
{ }


Parser::~Parser()
{ }


string Parser::parse(const string &input) const {
    string output;
    try {
        string commandName = ""; // tokens.nextToken();
    }
    catch (std::invalid_argument &e) {
        return CMD_NOT_FOUND;
    }
    
    return "Parse..."; //output;
}


