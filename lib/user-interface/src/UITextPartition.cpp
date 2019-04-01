//
//  UITextPartition.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.UITextPartition
//
//  Created by mpuchkov on 2019-03-25. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "UITextPartition.h"


namespace ui {


/* Constructors */

UITextPartition::UITextPartition(vector<string> &&elements)
: max_index(elements.size()), elements(std::move(elements))
{ }






/* Partitioning state */

bool UITextPartition::done() const {
    return (this->currentIndex >= this->max_index);
}


size_t UITextPartition::index() const {
    return this->currentIndex;
}


size_t UITextPartition::size() const {
    return this->elements.size();
}





/* Mutable current index control */

string UITextPartition::next() {
    string element = this->elements.at(currentIndex);
    this->advance();
    return element;
}


void UITextPartition::advance() {
    this->currentIndex++;
}


void UITextPartition::invalidate() {
    this->currentIndex = this->max_index;
}





/* Operators */

string UITextPartition::operator[](size_t index) {
    return this->elements[index];
}

string UITextPartition::operator[](size_t index) const {
    return this->elements[index];
}


} /* namespace ui */
