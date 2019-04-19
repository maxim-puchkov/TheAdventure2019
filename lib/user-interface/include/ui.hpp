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
namespace text {


// Type aliases
inline namespace {
    typedef std::string Text;
    typedef std::vector<Text> TextBlock;

    using Word = Text;
    using TextLine = Text;
    
    inline namespace io {
        using IStream = std::istringstream;
        using IStreamIterator = std::istream_iterator<Text>;
        using OStream = std::ostringstream;
        using OStreamIterator = std::ostream_iterator<Text>;
    } /* namespace io */
} /* namespace */





// Default width of all Description lines is 80 characters.
inline namespace defaults {
    const TextLine EMPTY;
    const std::size_t LINE_WIDTH = 80;
} /* namespace defaults */


// Common text output styles
namespace styles {
using Delimiter = Text;

inline namespace delimiters {
    const Text CS = ", ";
    const Text NL = "\n";
    const Text WS = " ";
} /* namespace delimiters */
} /* namespace styles */


} /* namespace text */
} /* namespace ui */

#endif /* ui_hpp */
