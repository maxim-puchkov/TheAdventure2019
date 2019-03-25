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

#include "UILibrary.pch"
using std::string;
using std::vector;


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
    
    UITextPartition(vector<string> &&elements);
    
    string next();
    
    bool done() const;
    
    void advance();
    
    void invalidate();
    
    size_t index() const;
    
    size_t size() const;
    
    string operator[](size_t index) const;
    
    const size_t max_index;
    
private:
    
    size_t currentIndex;
    
    vector<string> elements;
    
};

#endif /* UITextPartition_h */
