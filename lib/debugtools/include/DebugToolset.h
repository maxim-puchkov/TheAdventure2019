//
//  DebugToolset.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Debugger
//
//  Created by mpuchkov on 2019-03-24. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef DebugToolset_h
#define DebugToolset_h

#include <iostream>
#include <string>

namespace debug {

inline namespace colors {
    const std::string RED = "\u001b[31m";
    const std::string RESET = "\u001b[0m";
}


static std::string PrefixMessage = "\tDebug: ";

static void highlight() {
    std::cout << RED;
}

static void reset() {
    std::cout << RESET;
}

template<typename ...T>
static void print(T &&...ts) {
    std::cout << debug::PrefixMessage;
    highlight();
    (std::cout << ... << ts) << '\n';
    reset();
}


} /* namespace debug */

#endif /* DebugToolset_h */
