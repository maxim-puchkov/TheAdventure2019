//
//  ScriptController.h
//  adventure2019
//
//  Created by admin on 2019-02-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ScriptController_h
#define ScriptController_h

#include <vector>
#include <string>
#include <functional>
#include "Environment.h"
#include "Script.h"
#include "ScriptParser.h"


using std::vector;
using std::string;


using arguments = const vector<string>&;
using function = std::function<void(arguments)>;


void testScript(arguments args) {
    std::cout << "test" << std::endl;
    // send to chatwindow
}

//void spamScript(arguments args) {
//    string count = args[0];
//    string message = args[1];
//}





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
        this->scripts.bind("test", &testScript);
    }
    
    void requestInput() {
        this->inputRequested = true;
    }
    
    bool interrupt(string &&input) {
        if (this->inputRequested) {
            this->inputRequested = false;
            // Pass input to character
            return true;
        }
        
        return this->isScript(std::move(input));
    }
    
private:
    
    bool inputRequested = false;
    
    ScriptParser parser;
    
    Environment<string, function> scripts;
    
    bool isScript(string &&input) {
        try {
            Script scr = this->parser.parseScript(std::move(input), std::move(this->scripts));
        } catch (std::invalid_argument &e) {
            return false;
        }
        return true;
    }
    
};


#endif /* ScriptController_h */
