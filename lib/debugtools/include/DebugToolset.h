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

/// Format customization
inline namespace colors {
    const std::string RED = "\u001b[31m";
    const std::string RESET = "\u001b[0m";
}

/// Functionality customization
inline namespace config {
    static bool silenced = false;
}

/// Prefixes all outputted messages
// Message:
// "    Debug: <parameters>"
static std::string PrefixMessage = "Debug";



/* Debug Toolset */

static inline void highlight() {
    std::cout << RED;
}

static inline void reset() {
    std::cout << RESET;
}


/*!
 @function print
 @param ts Variadic generic parameters
 @discussion Universal function to print debug messages. Highlights messages
             and allows disabling all messages.
 */
template<typename ...T>
static void print(T &&...ts) {
    if (silenced) { return; }
    std::cout << '\t' << debug::PrefixMessage << ": ";
    highlight();
    (std::cout << ... << ts) << '\n';
    reset();
}


} /* namespace debug */

#endif /* DebugToolset_h */
