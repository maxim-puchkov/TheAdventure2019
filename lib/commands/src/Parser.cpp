/////////////////////////////////////////////////////////////////////////////
//                                  Parser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Parser.h"
#include "CommandDefinitions.h"


Parser::Parser()  {
    Parser::init(this);
}


Parser::~Parser()
{ }


Parser::Parser(Parser &&other)
: local(std::move(other.local)) { }


string Parser::process(const string &input) const {
    string output;
    try {
        TokenizedString tokens(std::move(input));
        
        string commandName = tokens.nextToken();
        
        Command command = this->local.lookup(commandName);
        
        std::vector<string> commandArguments = tokens.nextTokens(command.argCount);
        
        string remainingInput = tokens.split();
        
        commandArguments.push_back(remainingInput);
        
        output = command.function(commandArguments);
    }
    catch (std::invalid_argument &e) {
        return CMD_NOT_FOUND;
    }
    catch (string &customErrorText) {
        return DEF_CATCH_MESSAGE + customErrorText;
    }
    
    return output;
}


Environment<string, Command> Parser::localEnv() const {
    return this->local;
}


/*
 Environment<string, FnDescriptor> Parser::global;
 
 Environment<string, FnDescriptor> Parser::globalEnv() {
 return Parser::global;
 }
 */





/* Private */

void Parser::init(Parser *processor) {
    processor->createCommand("login", &test::exampleLogin, 2);          // login <bob> <123>
    processor->createCommand("help", &test::exampleShowHelp, 0);        // help
    processor->createCommand("error", &test::exampleThrowCustomErr, 1); // error <bob>
    processor->createCommand("tell", &test::exampleTell, 3);            // tell <bob> <msg>
    processor->createCommand("say", &test::exampleShowWorldSay, 0);     // say
    processor->createCommand("move", &test::exampleWorldMove, 1);       // move <dir>
    processor->createCommand("look", &test::exampleShowWorldLook, 1);   // look <obj>
}



void Parser::createCommand(string commandName, cmd_signature commandFn, int argCount) {
    Command commandFunction = {commandFn, argCount};
    this->local.bind(commandName, commandFunction);
}




/*
string Parser::availableCommands(const vector<string>&) {
    std::stringstream result("");
    std::queue<const string> commands = Parser::global.keys();
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
