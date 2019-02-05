/////////////////////////////////////////////////////////////////////////////
//                                  ScriptParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "ScriptParser.h"


ScriptParser::ScriptParser() { ScriptParser::init(this); }


ScriptParser::~ScriptParser() { }


void ScriptParser::parse(const string &input) const {
    try {
        size_t position = input.find(" ");
        string name = input.substr(0, position);
        
        
        std::istringstream text(input.substr(position + 1));
        vector<string> arguments{std::istream_iterator<string>{text},
                                 std::istream_iterator<string>{}};
        
        
        command fn = this->env.lookup(name);
        fn(arguments);
    } catch (std::invalid_argument &e) {
        // return CMD_NOT_FOUND;
    }
}

void ScriptParser::createCommand(const string &name, command function) {
    this->env.bind(name, function);
}





// Private



void ScriptParser::init(ScriptParser *p) {

    
    /*
    p->createCommand("login",    &accounts::command_login);
    p->createCommand("logout",   &accounts::command_logout);
    p->createCommand("login", &test::exampleLogin, 2);          // login <bob> <123>
    p->createCommand("help", &test::exampleShowHelp, 0);        // help
    p->createCommand("error", &test::exampleThrowCustomErr, 1); // error <bob>
    p->createCommand("tell", &test::exampleTell, 3);            // tell <bob> <msg>
    p->createCommand("say", &test::exampleShowWorldSay, 0);     // say
    p->createCommand("move", &test::exampleWorldMove, 1);       // move <dir>
    p->createCommand("look", &test::exampleShowWorldLook, 1);   // look <obj>
     */
    
}




