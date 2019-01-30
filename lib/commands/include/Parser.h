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

#include "Command.h"
#include "Environment.h"
#include "TokenizedString.h"

using std::vector;
using std::string;

const string CMD_HELP = "help";
const string DELIMETER = ", ";

const string DEF_CATCH_MESSAGE = "Exception caught. Details: ";
const string CMD_NOT_FOUND = "Invalid command. See available: " + CMD_HELP;


// Function must return string and take one "const vector<string>&" argument
//typedef string (*function_ptr)(const vector<string>&);

using cmd_signature = std::function<string(vector<string>&)>;


// Function pointer and number of arguments
struct Command {
    cmd_signature function;
    int argCount;
};



/**
 *  @class CommandProcessor
 *
 *  @brief Stores built-in commands and evaluates string input
 *
 *  A small compiler that will be useful for for client-side
 *  commands, scripting, crafting, or minigame implementation.
 */
class CommandProcessor {
public:
    
    CommandProcessor();
    
    ~CommandProcessor();
    
    CommandProcessor(CommandProcessor &&other);
    
    
    // Tokenize and evaluate input
    string process(const string &input) const;
    
    
    // Local map
    Environment<string, Command> localEnv() const;
    
    
    // (Optional) Global map
    // static Environment<string, FnDescriptor> globalEnv();
    
    
    //
    // string availableCommands();
    
    
    // Add a new command
    void createCommand(string commandName, cmd_signature commandFn, int argCount);
    
    
private:
    
    static void init(CommandProcessor *processor);
    
    Environment<string, Command> local;
    
    // static Environment<string, FnDescriptor> global;
    
};