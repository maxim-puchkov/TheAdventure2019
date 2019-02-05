/////////////////////////////////////////////////////////////////////////////
//                                  ScriptParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "ScriptParser.h"


ScriptParser::ScriptParser() { ScriptParser::init(this); }


ScriptParser::~ScriptParser() { }


void ScriptParser::parse(string &&input) const {
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


//void ScriptParser::createCommand(const string &name, command function) {
//    this->env.bind(name, function);
//}


//void ScriptParser::init(ScriptParser *p) {
//    // p->createCommand("login",    &accounts::command_login);
//}




