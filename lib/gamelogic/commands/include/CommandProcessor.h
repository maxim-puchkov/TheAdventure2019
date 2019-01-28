/////////////////////////////////////////////////////////////////////////////
//                                  CommandProcessor
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
#include "TokenizedString.h"
#include "CommandDefintions.h" // test::

using std::vector;
using std::string;

const string CMD_HELP = "help";
const string DELIMETER = ", ";

const string DEF_CATCH_MESSAGE = "Exception caught. Details: ";
const string CMD_NOT_FOUND = "Invalid command. See available: " + CMD_HELP;


// Function must return string and take one "const vector<string>&" argument
typedef string (*function_ptr)(const vector<string>&);


// Function pointer and number of arguments
struct FnDescriptor {
    function_ptr functionPtr;
    int argCount;
};


/**
 *  @class CommandProcessor
 *
 *  @brief Stores built-in commands and evaluates string input
 */
class CommandProcessor {
public:
    
    CommandProcessor();
    
    ~CommandProcessor();
    
    // Move local commands instead of copying
    CommandProcessor(CommandProcessor &&other);
    
    
    // Tokenize and evaluate input
    string process(const string &input) const;
    
    
    // Local map
    Environment<string, FnDescriptor> localEnv() const;
    
    
    // (Optional) Global map
    // static Environment<string, FnDescriptor> globalEnv();
    
    
    //
    // string availableCommands();
    
    
    // Add a new command
    void createCommand(string commandName, function_ptr commandFn, int argCount);
    
    
private:
    
    static void init(CommandProcessor *processor);
    
    Environment<string, FnDescriptor> local;
    
    // static Environment<string, FnDescriptor> global;
    
};
