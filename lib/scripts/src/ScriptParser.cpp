/////////////////////////////////////////////////////////////////////////////
//                                  ScriptParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "ScriptParser.h"


ScriptParser::ScriptParser() { }


ScriptParser::~ScriptParser() { }


Script ScriptParser::parseScript(string &&input, Environment<string, function> &&env) const noexcept(false) {
    size_t position = input.find(" ");
    string name = input.substr(0, position);
    
    
    istringstream text(input.substr(position + 1));
    vector<string> arguments{istream_iterator<string>{text},
                             istream_iterator<string>{}};
    
    
    function fn = env.lookup(name);
    return {fn, arguments};
}


//void ScriptParser::createCommand(const string &name, command function) {
//    this->env.bind(name, function);
//}


//void ScriptParser::init(ScriptParser *p) {
//    // p->createCommand("login",    &accounts::command_login);
//}




