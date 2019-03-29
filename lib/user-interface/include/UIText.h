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

#include "UIPrefixHeader.pch"
#include "UITextPartition.h"


namespace ui {

inline namespace text {
    const size_t WIDTH = 80;
    const uint8_t RESERVE = 5;
}


/*!
 @class UIText
 
 @brief User Interface text class
 
 @discussion Formats text to fit within specified width
 */
class UIText {
public:
    
    /* Constructors */
    
    UIText(const string &source);
    
    UIText(const string &source, size_t width);
    
    
    
    /* Change text style */
    
    void format();
    
    
    
    /* Text */
    
    string data() const;
    
    vector<string> arrangedSource() const;
    
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
    string nextLine(UITextPartition &partition) const;
    
    /*!
     @function breakLines
     @param partition Partitioned words of full text input
     @return Lines of words with specified width
     */
    UITextPartitionResult partition(UITextPartition &&partition) const;
    
    
    
    /* Data members */
    
    string source;
    
    vector<string> lines;
    
    size_t length;
    
    size_t width;
    
};


} /* namespace ui */

#endif /* UIText_h */
