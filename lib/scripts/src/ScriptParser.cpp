/////////////////////////////////////////////////////////////////////////////
//                                  ScriptParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "ScriptParser.h"


ScriptParser::ScriptParser() { }


ScriptParser::~ScriptParser() { }


vector<string> ScriptParser::parseInput(string &&input) const noexcept {
    istringstream text(input);
    return {istream_iterator<string>{text}, istream_iterator<string>{}};
}


Script ScriptParser::parseScript(string &&script, Environment<string, function> &&env) const noexcept(false) {
    size_t position = script.find(WHITESPACE);
    string name = script.substr(0, position);
    string body = script.substr(position + 1);
    
    vector<string> args = this->parseInput(std::move(body));
    
    function fn = env.lookup(name);
    return {fn, args};
}


//void ScriptParser::createCommand(const string &name, command function) {
//    this->env.bind(name, function);
//}


//void ScriptParser::init(ScriptParser *p) {
//    // p->createCommand("login",    &accounts::command_login);
//}




