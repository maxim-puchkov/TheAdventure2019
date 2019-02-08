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


template<typename F>
Functor<F> createFunctor(F f) {
    return Functor<F>(f);
}






template<class F>
struct ReturnType;

template<class R, class ...As>
struct ReturnType<R(*)(As...)> {
    using type = R;
};


template<>
struct ReturnType<void> {
    using type = void;
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
    
    template<typename ...T>
    /* R */ void operator()(T &&...ts) {
        this->f(std::forward<T>(ts)...);
    }
    
    int rtype() {
        print(this->f.target_type().name());
        return -1;
    }
    
private:
    
    const unsigned int argCount = sizeof ...(As);
    
    std::function<R(As...)> f;

    
};


// <void>

#endif /* Functor_h */
