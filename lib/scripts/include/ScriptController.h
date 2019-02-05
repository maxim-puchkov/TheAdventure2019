//
//  ScriptController.h
//  adventure2019
//
//  Created by admin on 2019-02-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ScriptController_h
#define ScriptController_h

#include "ScriptController.h"


/**
 *  @class ScriptController
 *
 *  @brief Controlls character's scripts.
 *
 *  Will be assigned to all avatars to
 *  parse, validate, and run scripts AND
 *  request input for non-server interactions.
 */
class ScriptController {
public:
    
    ScriptController() {
        
    }
    
private:
    
    ScriptParser parser;
    
};


#endif /* ScriptController_h */
