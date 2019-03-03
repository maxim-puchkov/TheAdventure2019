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
#include <string>

/*
template<string NAME, string ARGS>
 struct MetaCommand { };

template<> struct MetaCommand<
{ };
*/

//
//
//
//
//
//
//
//
//
//
//
//template<class>
//class Command;
//
//
//
////template<class F>
////class Command : Command<decltype(&F::operator())> { };
//
//
//template<class F, typename ...T>
//Command<F> createCommand(F f, T &&...ts) {
//    Functor<F> functor = createFunctor(f);
//    int argc = sizeof ...(ts);
//    if (functor.argc() == argc) {
//        print("OK");
//        Command<F> cmd = Command<F>(f);
//        return cmd;
//    }
//
//    // Parser will catch exceptions
//    print("Command constructor ARGC error");
//    throw(argc);
//
//}
//
//
//
//
//
//
//
//
//
//template<typename R, typename ...A>
//class Command<R(*)(A...)> {
//public:
//
//
//
//    Command(std::function<R(A...)> f) {
//        this->function = f;
//    }
//
////    Command(Functor<R(A...)> f) {
////        this->functor = f;
////    }
//
////    R operator()(A &&...as) {
////        this->functor(std::forward<A>(as)...);
////    }
//
//    R operator()(A &&...as) {
//        int asCount = sizeof ...(as);
//        print("Size of as: ");
//        print(asCount);
//        print("");
//        return this->function(std::forward<A>(as)...);
//    }
//
//private:
//
//    std::function<R(A...)> function;
//
//};

#endif /* Command_h */
