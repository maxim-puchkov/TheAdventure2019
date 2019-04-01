/*!
 @header print
 
 @brief Pretty debugging.
 
 Use functions in this header to display debug messages.
 Code
     debug::prefix("my class name");
     debug::print("total things created ", 123, '/', 124);
 will print
    "   my class name: total things created 123/124"
 
 @warning temporary
 */

#ifndef print_h
#define print_h

#include <iostream>
#include <string>
#include "bad_dealloc.h" // test


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
    static bool DefaultHighlight = false;
    
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

#endif /* print_h */
