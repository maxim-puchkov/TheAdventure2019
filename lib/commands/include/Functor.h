//
//  Functor.h
//  adventure2019
//
//  Created by admin on 2019-01-29.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include <iostream>
#include <string>

#ifndef Functor_h
#define Functor_h


template<class F, typename ...T>
class Functor;

template<class F, typename ...T>
class Functor<F(T...)> {
public:
    
    ~Functor() { }
    
    Functor(F &&f, T &&...ts) {
        Functor(f, std::forward<T>(ts)...);
    }
    
    template<class R>
    void operator()(R &&r) {
        r();
    }
    
    void operator()(F &&f, T &&...ts) {
        f(std::forward<T>(ts)...);
    }
    
    F operator()(T &&...ts) {
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
    _Functor c = _Functor::_Functor(Test_2, "hi");
    
    c(Test);
    
    c(Test_2, ("username"));
    
    c(Test_3, "Login", "Password");
}

*/

#endif /* Functor_h */
