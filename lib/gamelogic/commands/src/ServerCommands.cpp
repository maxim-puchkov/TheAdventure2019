/////////////////////////////////////////////////////////////////////////////
//                                  ServerCommands
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "ServerCommands.h"

ServerCommands::ServerCommands() {
    
}

Environment<string, FnDescriptor> ServerCommands::builtInEnv() {
    return this->env;
}

void ServerCommands::defineNew(string commandName, function_ptr commandFn, int argCount) {
    FnDescriptor commandFunction = {commandFn, argCount};
    this->env.bind(commandName, commandFunction);
}

string ServerCommands::process(const string &input) {
    string output;
    try {
        TokenizedString tokens(std::move(input));
        
        string commandName = tokens.nextToken();
        
        FnDescriptor commandFn = this->env.lookup(commandName);
        
        std::vector<string> commandArguments = tokens.spaceSeparatedTokens(commandFn.argCount);
        
        output = commandFn.functionPtr(commandArguments);
        
        // [&output](string x, string y) { commandFn.functionPtr(x, y); };
    } catch (std::invalid_argument &e) {
        return e.what();
    }
    
    return output;
}


