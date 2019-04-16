//
//  UITextPartition.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.UITextPartition
//
//  Created by mpuchkov on 2019-03-25. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef UITextPartition_h
#define UITextPartition_h

#include "ui.hpp"


namespace ui {
namespace text {


/*!
 @struct UITextPartitionResult
 
 @brief Stores lines and total length of source text partitioning
 */
struct UITextPartitionResult {
    
    TextBlock block;
    
    std::size_t width;
    
    std::size_t length;
    
};






/*!
 @class UITextPartition
 
 @brief Iterates over words to construct lines of required length
 */
class UITextPartition {
public:

    /* Constructors */
    UITextPartition(TextBlock &&block);
    
    
    /* Constant values */
    const std::size_t max_index;
   
    
    
    
    /* Partitioning state */
    bool done() const;
    std::size_t index() const;
    length_t length() const;
    
    
    
    /* Scan every word */
    Word next();
    void advance();
    
    
    void invalidate();
    
    
    
    /* Operators */
    TextLine operator[](std::size_t index);
    TextLine operator[](std::size_t index) const;
    
    UITextPartition& operator++();
    
private:
    
    TextBlock lines;
    
    std::size_t currentIndex = 0;
    
};


} /* namespace text */
} /* namespace ui */

#endif /* UITextPartition_h */
