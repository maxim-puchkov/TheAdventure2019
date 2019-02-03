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

using arguments = const vector<string>&;
using command = std::function<void(arguments)>;

const string CMD_HELP = "help";
const string CMD_NOT_FOUND = "Invalid command. See available: " + CMD_HELP;


class CommandParser {
public:
    
    CommandParser();
    
    ~CommandParser();
    
    void parse(const string &input) const;
    
    void createCommand(const string &name, command function);
    
private:
    
    static void init(CommandParser *p);
    
    Environment<string, command> env;
    
};
