/////////////////////////////////////////////////////////////////////////////
//                              CommandDefintions
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef CommandDefintions_h
#define CommandDefintions_h

#include "WorldManager.h" // remove later
#include "Exit.h"
#include "Character.h"
#include "Avatar.h"
#include "User.h"

using std::string;
using std::vector;

string log(string s1, string s2) {
    return s1 + s2;
}

string exampleLogin(const vector<string> &args) {
    string username = args[0];
    string password = args[1];
    
    return "Test output: User " + username + " " + password + " logged in!";
}

string exampleShowHelp(const vector<string> &args) {
    return "Available example commands: login, help, say, move, look";
}

/* In game manager */
    WorldManager TEMP_worldManager;

    Avatar TEMP_usersAvatar;
    Character TEMP_character = TEMP_usersAvatar;
//  pass to Game manager, take arguments from vector,
//  validate, and pass to existing world manager's function



string exampleShowWorldSay(const vector<string> &args) {
    string message = args[0]; // does not capture whole message
    
    string output = TEMP_worldManager.say(&TEMP_character, args[0]);
    output += "(" + message + ")";
    
    return output;
}



string exampleShowWorldLook(const vector<string> &args) {
    string object = args[0];
    
    string output;
    if (object != "") {
        // Change WorldManager to take argument (const Character &)
        // and pass as (TEMP_character)
        output = TEMP_worldManager.look(&TEMP_character, object);
    } else {
        output = TEMP_worldManager.look(&TEMP_character);
    }
    return output;
}



string exampleWorldMove(const vector<string> &args) {
    string direction = args[0];
    //Exit::CardinalDirection cDir = Exit::CardinalDirection.NONE;
    // <<<string>>> output = TEMP_worldManager.move(&TEMP_character, <<<Exit::CardinalDirection>>>);
    return "output";
}

/* In game manager */


CommandProcessor BuiltInProcessor() {
    CommandProcessor commands; // instance of a processor
    
    
    // Specify name, function, and arguments required
    string cmdName = "help";
    function_ptr cmdFn = &exampleShowHelp;
    int argCount = 0;
    commands.defineNew(cmdName, cmdFn, argCount); // help
    
    
    commands.defineNew("login", &exampleLogin, 2); // login <user> <pass>
    commands.defineNew("say", &exampleShowWorldSay, 1); // say <text> (currently only next word)
    commands.defineNew("move", &exampleWorldMove, 1); // move <dir>
    commands.defineNew("look", &exampleShowWorldLook, 1); // look <obj>
    
    
    
    return commands;
}



#endif /* CommandDefintions_h */

