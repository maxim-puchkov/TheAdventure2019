//
//  ui.hpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ui
//
//  Created by mpuchkov on 2019-04-14. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ui_hpp
#define ui_hpp

#include "Freestanding.pch"
#include "UIPrefixHeader.pch"


namespace ui {


using length_t = std::size_t;


namespace text {


// Type aliases
inline namespace {
using Letter = char;
using Symbol = Letter;

using Text = std::string;
using Word = Text;
using Line = Text;
using TextLine = Text;

using Block = std::vector<Line>;
using TextBlock = std::vector<TextLine>;

using ui_istream = std::istringstream;
using ui_istream_iterator = std::istream_iterator<Text>;

using ui_ostream = std::ostringstream;
using ui_ostream_iterator = std::ostream_iterator<Text>;
}


// Default width of all Description lines is 80 characters.
// Default storage reserves five lines of width 80.
inline namespace defaults {
    const Line EMPTY;
    const std::size_t LINE_WIDTH = 80;
    const std::size_t LINE_RESERVE = 5;
} /* namespace defaults */


// Common text output styles
namespace styles {
    using Delimiter = Text;
    
    inline namespace delimiters {
        const Delimiter CS = ", ";
        const Delimiter NL = "\n";
        const Delimiter WS = " ";
    }
} /* namespace styles */


} /* namespace text */
} /* namespace ui */


#endif /* ui_hpp */
