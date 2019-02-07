//
//  Script.h
//  adventure2019
//
//  Created by admin on 2019-02-04.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Script_h
#define Script_h

#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;

using arguments = const vector<string>&;
using function = std::function<void(arguments)>;

class Script {
public:
    
    Script(function &&fn, vector<string> &&args) { }
    
    bool validateSize(unsigned int argc) const noexcept  {
        return (this->args.size() == argc);
    }
    
    bool validateArgLength(string &&argument, unsigned int minLength) const noexcept {
        return (argument.length() == minLength);
    }
    
    void operator()() {
        fn(std::move(this->args));
    }
    
    // void operator()(vector<string> &&args);
    
private:
    
    function fn;
    
    vector<string> args;
    
};












/* ~> cpp */

/*

bool Script::validateSize(unsigned int argc) const noexcept

bool Script::validateArgLength(string &&argument, unsigned int minLength) const noexcept

void Script::operator()()
 
 */

#endif /* Script_h */
