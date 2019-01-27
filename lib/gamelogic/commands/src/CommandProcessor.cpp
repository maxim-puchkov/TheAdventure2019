/////////////////////////////////////////////////////////////////////////////
//                                  CommandProcessor
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "CommandProcessor.h"

CommandProcessor::CommandProcessor() {
    this->env.setExceptionText(CMD_NOT_FOUND);
}

CommandProcessor::~CommandProcessor() {
    
}

Environment<string, FnDescriptor> CommandProcessor::builtInEnv() {
    return this->env;
}

void CommandProcessor::defineNew(string commandName, function_ptr commandFn, int argCount) {
    FnDescriptor commandFunction = {commandFn, argCount};
    this->env.bind(commandName, commandFunction);
}

string CommandProcessor::process(const string &input) {
    string output;
    try {
        TokenizedString tokens(std::move(input));
        
        string commandName = tokens.nextToken();
        
        FnDescriptor commandFn = this->env.lookup(commandName);
        
        std::vector<string> commandArguments = tokens.spaceSeparatedTokens(commandFn.argCount);
        
        output = commandFn.functionPtr(commandArguments);
    } catch (std::invalid_argument &e) {
        // int ERROR = 0;
        return e.what();
    } catch (string customError) {
        return customError;
    }
    
    // int OK = 1;
    return output;
}
