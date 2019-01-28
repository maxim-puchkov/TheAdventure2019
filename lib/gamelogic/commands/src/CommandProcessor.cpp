/////////////////////////////////////////////////////////////////////////////
//                                  CommandProcessor
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "CommandProcessor.h"
#include "CommandDefintions.h"


CommandProcessor::CommandProcessor() { CommandProcessor::init(this); }


CommandProcessor::~CommandProcessor() { }


CommandProcessor::CommandProcessor(CommandProcessor &&other)
: local(std::move(other.local)) { }


string CommandProcessor::process(const string &input) const {
    string output;
    try {
        TokenizedString tokens(std::move(input));
        
        string commandName = tokens.nextToken();
        
        FnDescriptor commandFn = this->local.lookup(commandName);
        
        std::vector<string> commandArguments = tokens.nextTokens(commandFn.argCount);
        
        string remainingInput = tokens.split();
        
        commandArguments.push_back(remainingInput);
        
        output = commandFn.functionPtr(commandArguments);
    }
    catch (std::invalid_argument &e) {
        return CMD_NOT_FOUND;
    }
    catch (string &customErrorText) {
        return DEF_CATCH_MESSAGE + customErrorText;
    }
    
    return output;
}


Environment<string, FnDescriptor> CommandProcessor::localEnv() const {
    return this->local;
}


/*
 Environment<string, FnDescriptor> CommandProcessor::global;
 
 Environment<string, FnDescriptor> CommandProcessor::globalEnv() {
 return CommandProcessor::global;
 }
 */









// Private

void CommandProcessor::init(CommandProcessor *processor) {
    std::cout << "Running init ...\n";
    
    processor->createCommand("login", &test::exampleLogin, 2);          // login <bob> <123>
    processor->createCommand("help", &test::exampleShowHelp, 0);        // help
    processor->createCommand("error", &test::exampleThrowCustomErr, 1); // error <bob>
    processor->createCommand("tell", &test::exampleTell, 3);            // tell <bob> <msg>
    processor->createCommand("say", &test::exampleShowWorldSay, 0);     // say
    processor->createCommand("move", &test::exampleWorldMove, 1);       // move <dir>
    processor->createCommand("look", &test::exampleShowWorldLook, 1);   // look <obj>
    
}



void CommandProcessor::createCommand(string commandName, function_ptr commandFn, int argCount) {
    FnDescriptor commandFunction = {commandFn, argCount};
    this->local.bind(commandName, commandFunction);
}




/*
 string CommandProcessor::availableCommands(const vector<string>&) {
 std::stringstream result("");
 std::queue<const string> commands = CommandProcessor::global.keys();
 while (!commands.empty()) {
 result << commands.front();
 commands.pop();
 if (!commands.empty()) {
 result << DELIMETER;
 }
 }
 return result.str();
 }
 */
