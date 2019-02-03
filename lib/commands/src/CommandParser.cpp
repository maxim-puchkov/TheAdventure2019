/////////////////////////////////////////////////////////////////////////////
//                                  CommandParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "CommandParser.h"


CommandParser::CommandParser() { CommandParser::init(this); }


CommandParser::~CommandParser() { }


string CommandParser::parse(const string &input) const {
    string output;
    try {

    }
    catch (std::invalid_argument &e) {
        return CMD_NOT_FOUND;
    }
    
    return output;
}







// Private

void CommandParser::init(CommandParser *p) {
    std::cout << "Running init ...\n";
    
    /*
    p->createCommand("login", &test::exampleLogin, 2);          // login <bob> <123>
    p->createCommand("help", &test::exampleShowHelp, 0);        // help
    p->createCommand("error", &test::exampleThrowCustomErr, 1); // error <bob>
    p->createCommand("tell", &test::exampleTell, 3);            // tell <bob> <msg>
    p->createCommand("say", &test::exampleShowWorldSay, 0);     // say
    p->createCommand("move", &test::exampleWorldMove, 1);       // move <dir>
    p->createCommand("look", &test::exampleShowWorldLook, 1);   // look <obj>
     */
    
}



void CommandParser::createCommand(string commandName, std::function<string(vector<string> &)> commandFn) {
    this->env.bind(commandName, commandFn);
}
