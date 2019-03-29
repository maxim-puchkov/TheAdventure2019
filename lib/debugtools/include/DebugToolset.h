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

using std::string;
using std::cout;


inline namespace config {
    
    inline namespace colors {
        const string RED = "\u001b[31m";
        const string RESET = "\u001b[0m";
    } /* namespace colors */
    
    /*! Prefixes all outputted messages */
    static string PrefixMessage = "Debug";

    /*! Messages will not be displayed if set true */
    static bool silenced = false;
    
} /* namespace config */





/*! Highlight text */
static inline void highlight() {
    cout << RED;
}


/*! Reset text format */
static inline void reset() {
    cout << RESET;
}


/*! Change prefix message */
static inline void prefix(const std::string &message) {
    debug::PrefixMessage = message;
}


/*!
 @function print
 @param args Variadic generic arguments
 @discussion Universal function to print debug messages. Highlights messages
             and allows silencing all messages.
 */
template<typename ...Arguments>
static void print(Arguments &&...args) {
    
    // Discard all messages if silenced
    if (silenced) { return; }
    
    // Print caller's prefix
    cout << '\t' << debug::PrefixMessage << ": ";
    
    // Highlight and print messages
    highlight();
    (cout << ... << args);
    
    reset();
    cout << '\n';
    
}


} /* namespace debug */

#endif /* DebugToolset_h */
