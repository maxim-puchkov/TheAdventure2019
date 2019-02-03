//
//  CommandDefinitions.cpp
//  adventure2019
//
//  Created by admin on 2019-02-02.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include <stdio.h>

#include "CommandDefinitions.h"

namespace accounts {
    
    
    void command_login(arguments args) {
        string id = args[0];  // ?
        string username = args[1];
        string password = args[2];
        
        AccountManager::login(id, username, password);
    }
    
    void command_logout(arguments args) {
        string username = args[0];
        
        AccountManager::logOut(username);
    }
    
    
}
