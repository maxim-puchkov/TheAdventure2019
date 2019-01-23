/////////////////////////////////////////////////////////////////////////////
//                                  ServerCommands
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <regex>
#include "TokenizedString.h"
#include "Environment.h"

using std::vector;
using std::string;

/**
 *  @class ServerCommands
 *
 *  @brief Stores built-in commands and evaluates string input
 */
class ServerCommands {
public:
    // Function must return string and take one "const vector<string>&" argument
    typedef string (*function_ptr)(const vector<string>&);
    
    // Function pointer and number of arguments
    struct FnDescriptor {
        function_ptr functionPtr;
        int argCount;
    };
    
    // Add a new command
    void createNew(string commandName, function_ptr commandFn, int argCount);
    
    Environment<string, FnDescriptor> builtIn();
    
    // Tokenize and evaluate input
    string process(const string &&input) noexcept;
    
private:
    
    // Built-in commands
    Environment<string, FnDescriptor> env;
    
};
