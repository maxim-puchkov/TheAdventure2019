/////////////////////////////////////////////////////////////////////////////
//                                  CommandParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef CommandParser_h
#define CommandParser_h

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using std::vector;
using std::string;


const string CMD_HELP = "help";
const string CMD_NOT_FOUND = "Invalid command. See available: " + CMD_HELP;


/**
 *  @class CommandParser
 *
 *  @brief ...
 *
 *  ...
 */
class CommandParser {
public:
    
    CommandParser();
    
    ~CommandParser();
    
    // Tokenize and parse input
    string parse(const string &input) const;
    
    
private:
    
};

#endif /* CommandParser_h */
