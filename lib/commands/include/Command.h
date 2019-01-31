//
//  Command.h
//  adventure2019
//
//  Created by admin on 2019-01-29.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include <iostream>
#include <string>

#ifndef Command_h
#define Command_h

class _Command {
public:
    
    ~_Command() { }
    
    template<class F, class ...T>
    _Command(F &&f, T &&...ts) {
        _Command(f, std::forward<T>(ts)...);
    }
    
    template<class F>
    void operator()(F &&f) {
        f();
    }
    
    template<class F, class ...T>
    void operator()(F &&f, T &&...ts) {
        f(std::forward<T>(ts)...);
    }
    
    template<class R, class ...T>
    R operator()(T &&...ts) {
        return f(std::forward<T>(ts)...);
    }
    
private:
    
};





/* Tests */

/*

// Outputs: Hello, World!
void Test(...) {
    std::cout << "Hello, World!\n";
}

// Outputs: Hello, <Input>!
void Test_2(std::string Input) {
    std::cout << "Hello, " << Input << "! \n";
}

// Outputs: Login: <Login>, Password: <Password>!
void Test_3(std::string Login, std::string Password) {
    std::cout << "Login: " << Login << ", Password: " << Password << "! \n";
}


void test() {
    _Command c = _Command::_Command(Test_2, "hi");
    
    c(Test);
    
    c(Test_2, ("username"));
    
    c(Test_3, "Login", "Password");
}

*/

#endif /* Command_h */
