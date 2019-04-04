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

#include "UIPrefixHeader.pch"

using std::string;
using std::vector;


namespace ui {


/*!
 @struct UITextPartitionResult
 
 @brief Stores lines and total length of source text partitioning
 */
struct UITextPartitionResult {
    
    vector<string> content;
    
    size_t length;
    
};






/*!
 @class UITextPartition
 
 @brief Iterates over words to construct lines of required length
 */
class UITextPartition {
public:
    
    /* Constant values */
    
    const size_t max_index;
    
    
    
    /* Constructors */
    
    UITextPartition(vector<string> &&elements);
    
    
    
    /* Partitioning state */
    
    bool done() const;
    
    size_t index() const;
    
    size_t size() const;
    
    
    
    /* Mutable current index control */
    
    string next();
    
    void advance();
    
    void invalidate();
    
    
    
    /* Operators */
    
    string operator[](size_t index);
    string operator[](size_t index) const;
    
private:
    
    size_t currentIndex = 0;
    
    vector<string> elements;
    
};


} /* namespace ui */

#endif /* UITextPartition_h */
