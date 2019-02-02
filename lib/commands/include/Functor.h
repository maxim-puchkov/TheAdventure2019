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


template<typename ...T>
void print(T &&...ts) {
    (std::cout << ... << ts) << std::endl;
}


template<class>
class Functor;

template<typename R, class C, typename ...As>
class Functor<R(C::*)(As...)> {
    Functor() {
        print("R(C::*)(As...)");
    }
};


template<class F>
Functor<F> createFunctor(F f) {
    return Functor<F>(f);
}

/*
template<class F, typename ...T>
Functor<F> createCommand(F f, T &&...ts) {
    Functor<F> functor = createFunctor(f);
    int argc = sizeof ...(ts);
    if (functor.argc() == argc) {
        print("OK");
        return functor;
    }
    
    print("error");
    // return 6;
    throw(argc);
}
*/






template<class P>
class ArgumentPack {
public:
    
    
    
};










template<class F>
class Functor : Functor<decltype(&F::operator())> { };

template<typename R, typename ...As>
class Functor<R(*)(As...)> {
public:
    
    Functor(std::function<R(As...)> func) {
        this->f = func;
    }
    
    ~Functor() { }
    
    const unsigned int argc() {
        return this->argCount;
    }
    
    /*
    template<typename ...T>
    R operator()(T &&...ts) {
        if (this->validate(std::forward<T>(ts)...)) {
            
        }
    }
    */
     
    template<typename ...T>
    bool validate(T &&...ts) {
        int callArgs = sizeof...(ts);
        print("Call args: ", argCount);
        return callArgs == argCount;
    }
    
    std::function<R(As...)> f;
    
private:
    
    const unsigned int argCount = sizeof ...(As);
    
    
    
};


// <void>

//class Cmd {
//public:
//    template<typename ...T>
//    Cmd() {
//        int inputArgCount = sizeof...(argv);
//        if (argc != argv) {
//            
//        }
//    }
//}


#endif /* Functor_h */
