/////////////////////////////////////////////////////////////////////////////
//                              CommandDefintions
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef CommandDefintions_h
#define CommandDefintions_h

#include "AccountManager.h"


namespace accounts {

using accountmanager::AccountManager;

    void command_login(arguments args);
    
    void command_logout(arguments args);
    
}





namespace game {
    
    void command_say(arguments args) { }
    
    void command_yell(arguments args) { }
    
}

#include "../src/CommandDefinitions.cpp"

#endif /* CommandDefintions_h */
