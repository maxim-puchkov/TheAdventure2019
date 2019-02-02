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


template<class F, typename ...T>
Command<F> createCommand(F f, T &&...ts) {
    Functor<F> functor = createFunctor(f);
    int argc = sizeof ...(T);
    
    
    if (functor.argc() == argc) {
        Command<F> command = Command(functor.f);
        print("Command<F(T...)> created!");
        return command;
    }
    
    
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
template<typename R, typename ...T>
class Command<R(*)(T...)> {
public:
    
    

    Command(std::function<R(T...)> f) {
        this->function = f;
    }
    
//    Command(Functor<R(T...)> f) {
//        this->functor = f;
//    }
    
//    R operator()(A &&...as) {
//        this->functor(std::forward<A>(as)...);
//    }
    
private:
    
    std::function<R(T...)> function;
    
};

#endif /* Command_h */
