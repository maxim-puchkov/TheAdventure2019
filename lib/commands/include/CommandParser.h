/////////////////////////////////////////////////////////////////////////////
//                                  CommandParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <queue>
#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>

#include "Environment.h"

using std::vector;
using std::string;

const string CMD_HELP = "help";
const string DELIMETER = ", ";

const string DEF_CATCH_MESSAGE = "Exception caught. Details: ";
const string CMD_NOT_FOUND = "Invalid command. See available: " + CMD_HELP;


class CommandParser {
public:
    
    CommandParser();
    
    ~CommandParser();
    
    // Tokenize and evaluate input
    string parse(const string &input) const;
    
    // Add a new command
    void createCommand(string commandName, std::function<string(vector<string> &)> commandFn);
    
    
private:
    
    static void init(CommandParser *p);
    
    Environment<string, std::function<string(vector<string> &)>> env;
    
};
