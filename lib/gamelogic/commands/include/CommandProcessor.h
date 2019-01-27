/////////////////////////////////////////////////////////////////////////////
//                                  CommandProcessor
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <regex>
#include "Environment.h"
#include "TokenizedString.h"

// Function must return string and take one "const vector<string>&" argument
typedef string (*function_ptr)(const vector<string>&);


// Function pointer and number of arguments
struct FnDescriptor {
    function_ptr functionPtr;
    int argCount;
};

/* If needed
 struct CommandResult {
 int status;
 string text;
 };
 */

using std::vector;
using std::string;





/**
 *  @class CommandProcessor
 *
 *  @brief Stores built-in commands and evaluates string input
 */
class CommandProcessor {
public:
    
    CommandProcessor();
    
    ~CommandProcessor();
    
    // Add a new command
    void defineNew(string commandName, function_ptr commandFn, int argCount);
    
    Environment<string, FnDescriptor> builtInEnv();
    
    // Tokenize and evaluate input
    string process(const string &input);
    
private:
    
    // Built-in commands
    Environment<string, FnDescriptor> env;
    
};
