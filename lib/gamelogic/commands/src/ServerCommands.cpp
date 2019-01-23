/////////////////////////////////////////////////////////////////////////////
//                                  ServerCommands
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "ServerCommands.h"

Environment<string, ServerCommands::FnDescriptor> ServerCommands::builtIn() {
    return this->env;
}

void ServerCommands::createNew(string commandName, function_ptr commandFn, int argCount) {
    FnDescriptor commandFunction = {commandFn, argCount};
    this->env.bind(commandName, commandFunction);
}

string ServerCommands::process(const string &&input) noexcept {
    string output;
    try {
        TokenizedString tokens(std::move(input));
        
        string commandName = tokens.nextToken();
        
        FnDescriptor commandFn = this->env.lookup(commandName);
        
        std::vector<string> commandArguments = tokens.nextTokens(commandFn.argCount);
        
        output = commandFn.functionPtr(commandArguments);
    } catch (std::exception &e) {
        output = e.what();
    }
    
    return output;
}
