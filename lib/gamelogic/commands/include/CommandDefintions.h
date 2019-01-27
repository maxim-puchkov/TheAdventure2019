/////////////////////////////////////////////////////////////////////////////
//                              CommandDefintions
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef CommandDefintions_h
#define CommandDefintions_h

using std::string;
using std::vector;

string log(string s1, string s2) {
    return s1 + s2;
}

string exampleFunc1(const vector<string> &args) {
    string username = args[0];
    string password = args[1];
    return "Test output: User " + username + " " + password + " logged in!";
}

string exampleFunc2(const vector<string> &args) {
    return "Test output: Example User logged out!";
}

CommandProcessor defineAllCommands() {
    CommandProcessor commands;
    string cmdName = "login";
    function_ptr cmdFn = &exampleFunc1;
    int argCount = 2;
    
    commands.defineNew(cmdName, cmdFn, argCount); // login
    commands.defineNew("anything", &exampleFunc2, 0); // anything
    
    return commands;
}



#endif /* CommandDefintions_h */

