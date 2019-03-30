//
//  Tools.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Debugger
//
//  Created by mpuchkov on 2019-03-24. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Tools_h
#define Tools_h

#include <iostream>
#include <string>


namespace debug {

using std::string;
using std::cout;


inline namespace configuration {
    
    
    inline namespace colors {
        static string HIGHLIGHT_COLOR;
        static string HIGHLIGHT_RESET;
        
        const string RED = "\u001b[31m";
        const string RESET = "\u001b[0m";
        const string NONE = "";
    } /* namespace colors */
    
    
    /*! Messages will not be displayed if set true */
    static bool silenced = false;
    
    /*! */
    static bool DefaultHighlight = true;
    
    /*! Prefixes all outputted messages */
    static string PrefixMessage = "Debug";
    
    
} /* namespace config */



/*! Highlight text */
static inline void highlight() {
    cout << HIGHLIGHT_COLOR;
}


/*! Reset text format */
static inline void reset() {
    cout << HIGHLIGHT_RESET;
}


/*! Configure message highlight color */
static inline void enableHighlight(bool enable) {
    if (enable) {
        HIGHLIGHT_COLOR = RED;
        HIGHLIGHT_RESET = RESET;
    } else {
        HIGHLIGHT_COLOR = NONE;
        HIGHLIGHT_RESET = NONE;
    }
}


/*! Change prefix message */
static inline void prefix(const string &message) {
    debug::PrefixMessage = message;
    debug::enableHighlight(DefaultHighlight);
}


static inline void config(const string &message, bool enable) {
    debug::prefix(message);
    debug::enableHighlight(enable);
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

#endif /* Tools_h */
