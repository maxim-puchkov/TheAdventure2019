/////////////////////////////////////////////////////////////////////////////
//                              CommandDefintions
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef CommandDefintions_h
#define CommandDefintions_h

#include <vector>
#include <string>
#include "AccountManager.h"


using std::vector;
using std::string;


using arguments = const vector<string>&;
using command = std::function<void(arguments)>;


namespace accounts {

using accountmanager::AccountManager;

    void command_login(arguments args);
    
    void command_logout(arguments args);
    
}





namespace game {
    
    void command_say(arguments args); /* undefined */
    
    void command_yell(arguments args); /* undefined */
    
}

#include "../src/CommandDefinitions.cpp"

#endif /* CommandDefintions_h */
