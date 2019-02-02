//
//  Command.h
//  commands
//
//  Created by admin on 2019-02-01.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Command_h
#define Command_h

#include "Functor.h"

template<class>
class Command;



//template<class F>
//class Command : Command<decltype(&F::operator())> { };


template<class F, typename ...T>
Command<F> createCommand(F f, T &&...ts) {
    Functor<F> functor = createFunctor(f);
    int argc = sizeof ...(ts);
    if (functor.argc() == argc) {
        print("OK");
        Command<F> cmd = Command<F>(f);
        return cmd;
    }
    
    // Parser will catch exceptions
    print("Command constructor ARGC error");
    throw(argc);
    
}









/**
 *  @class ...
 *
 *  @brief ...
 *
 *  (current) Idea:
 *          1. Instantiate with:
 *                   (a) Command name;
 *                   (b) Functor with (only static?) std::function
 *                       and (single generic type) arguments.
 *          2. Command is only a valid functor. Throws.
 *          3. Command can be passed and called on demand.
 *          Optional 4. Generic generic parameters.
 *
 *  Code:
 *          1. A function:
 *             static int example(int a, int b) { return a+b; }
 *
 *          2. A map of a string to a function
 *             {{"example" : example}, {"say" : say}, .......}
 *
 *          3. User inputs and parser outputs:
 *                   (a) "example 2 3"   ~>     {"example", 2, 3}
 *                   (b) "example 1"     ~>     {"example, 1}
 *
 *          4. (a) OK:      f1 = createCommand(Functor(example), 2, 3)
 *             (b) Invalid: f2 = createCommand(Functor(example), 1)
 *
 *          5. If functor valid
 &                    cmd = Command(f1)
 *
 *          6. Call anywhere
 *                    ClassA.setCommandOf(ClassB, cmd)
 *                    result = ClassB.cmd()
 *                    // result = 2+3 = 5
 */
template<typename R, typename ...A>
class Command<R(*)(A...)> {
public:
    
    

    Command(std::function<R(A...)> f) {
        this->function = f;
    }
    
//    Command(Functor<R(A...)> f) {
//        this->functor = f;
//    }
    
//    R operator()(A &&...as) {
//        this->functor(std::forward<A>(as)...);
//    }
    
    R operator()(A &&...as) {
        int asCount = sizeof ...(as);
        print("Size of as: ");
        print(asCount);
        print("");
        return this->function(std::forward<A>(as)...);
    }
    
private:
    
    std::function<R(A...)> function;
    
};

#endif /* Command_h */
