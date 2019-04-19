//
//  UIText.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.UIText
//
//  Created by mpuchkov on 2019-03-25. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef UIText_h
#define UIText_h

#include "ui.hpp"
#include "UITextPartition.h"

namespace ui {
namespace text {

    
// using namespace styles;

/*!
 @class UIText
 
 @brief User Interface text class
 
 @discussion Formats text to fit within specified width
 */
class UIText {
public:
    
    /* Constructors */
    
    UIText(const Text &source);
    
    UIText(const Text &source, std::size_t width);
    
    
    
    /* Change text style */
    
    void format();
    
    
    
    /* Text */
    
    Text sourceText() const;
    
    TextBlock sourceBlock() const;
    
private:
    
    /*!
     @function words
     @return Vector of individual source text words without whitespaces.
     */
    UITextPartition words() const;
    
    /*!
     @function nextLine
     @param partition Text partition with current index
     @return Next line that can fit within the line width
     */
    TextLine nextLine(UITextPartition &partition) const;
    
    /*!
     @function breakLines
     @param partition Partitioned words of full text input
     @return Lines of words with specified width
     */
    Result partition(UITextPartition &&partition) const;
    
    
    
    /* Data members */
    
    Text source;
    TextBlock block;
    
    std::size_t block_length = 0;
    std::size_t width = LINE_WIDTH; // !
    
};


} /* namespace text */
} /* namespace ui */

#endif /* UIText_h */
