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

#include "UILibrary.pch"
#include "UITextPartition.h"


/*!
 @class UIText
 
 @brief User Interface text class
 
 @discussion Formats text to fit within specified width
 */
class UIText {
public:
    
    /* Constructors */
    
    UIText(const string &source);
    
    UIText(const string &source, uint16_t width);
    
    
    
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
    
    uint16_t width;
    
};

#endif /* UIText_h */
