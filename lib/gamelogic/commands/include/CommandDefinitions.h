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
#include "User.h" //

using std::string;
using std::vector;

namespace test { // test::
    
    /* In game manager >> */
    WorldManager TEMP_worldManager;
    Avatar TEMP_usersAvatar;
    Character TEMP_character = TEMP_usersAvatar;
    
    
    
    // Show help
    string exampleShowHelp(const vector<string> &args) {
        return "Available example commands: login, error, tell, help, say, move, look";
    }
    
    
    // Login, create user and avatar
    string exampleLogin(const vector<string> &args) {
        string username = args[0];
        string password = args[1];
        
        string output;
        if (username == "bob" && password == "123") {
            output = "Logged in user bob";
            user::User bobUser(username, password);
        } else {
            output = "Cannot login with (" + username + ", " + password + "): (login bob 123)";
        }
        
        return output;
    }
    
    
    // Customizable errors
    string exampleThrowCustomErr(const vector<string> &args) {
        string anything = args[0];
        throw (anything);
        return "can't return";
    }
    
    
    // Return errors
    string exampleTell(const vector<string> &args) {
        string username = args[0];
        string message = args[1];
        
        const string PROGRAM_EXCEPTION = "Client connection lost.";
        
        if (username != "bob") return "Can only tell <bob>";
        if (message.length() < 5) return "Message is too short";
        if (message.length() > 10) return "Message is too long";
        if (message == "bad_word") return "You cannot send this message";
        
        if (bool clientDisconnected = true) {
            throw PROGRAM_EXCEPTION;
        }
        
        return "Ok, sending " + message + " to " + username;
    }
    
    
    // Say
    string exampleShowWorldSay(const vector<string> &args) {
        string message = args[0]; // does not capture whole message, only next word
        
        string output = TEMP_worldManager.say(&TEMP_character, args[0]);
        output += "(" + message + ")";
        
        return output;
    }
    
    
    // Look
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
    
    
    // Not move
    string exampleWorldMove(const vector<string> &args) {
        string direction = args[0];
        //Exit::CardinalDirection cDir = Exit::CardinalDirection.NONE;
        // <<<string>>> output = TEMP_worldManager.move(&TEMP_character, <<<Exit::CardinalDirection>>>);
        return "output (not possible yet)";
    }
    
    /* << In game manager  */
    
}


#endif /* CommandDefintions_h */
