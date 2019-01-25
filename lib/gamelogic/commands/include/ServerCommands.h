/////////////////////////////////////////////////////////////////////////////
//                                  ServerCommands
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <regex>
#include "Environment.h"
#include "TokenizedString.h"

typedef string (*function_ptr)(const vector<string>&);

// Function pointer and number of arguments
struct FnDescriptor {
    function_ptr functionPtr;
    int argCount;
};

using std::vector;
using std::string;

/**
 *  @class ServerCommands
 *
 *  @brief Stores built-in commands and evaluates string input
 */
class ServerCommands {
public:
    
    ServerCommands();
    
    // Function must return string and take one "const vector<string>&" argument
    typedef string (*function_ptr)(const vector<string>&);
    
    // Add a new command
    void defineNew(string commandName, function_ptr commandFn, int argCount);
    
    Environment<string, FnDescriptor> builtInEnv();
    
    // Tokenize and evaluate input
    string process(const string &input);
    
    // Built-in commands
    Environment<string, FnDescriptor> env;
    
};
