/////////////////////////////////////////////////////////////////////////////
//                                  CommandParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "CommandParser.h"

CommandParser::CommandParser() { }

CommandParser::~CommandParser() { }

string CommandParser::parse(const string &input) const {
    
    size_t position = input.find(" ");
    string commandName = input.substr(0, position);
    string commandText = input.substr(position + 1);
    
    std::cout << commandName << " >>> '" << commandText << "'" << std::endl;
    
    string output;
    try {
        string commandName = ""; // tokens.nextToken();
    }
    catch (std::invalid_argument &e) {
        return CMD_NOT_FOUND;
    }
    
    return "Parse..."; //output;
}


