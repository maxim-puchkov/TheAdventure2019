//
//  UITextPartition.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.UITextPartition
//
//  Created by mpuchkov on 2019-03-25. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "UITextPartition.h"



UITextPartition::UITextPartition(vector<string> &&elements)
: elements(std::move(elements)), currentIndex(0), max_index(elements.size())
{ }


string UITextPartition::next() {
    string element = this->elements.at(currentIndex);
    this->advance();
    return element;
}


bool UITextPartition::done() const {
    return (this->currentIndex >= this->max_index);
}


void UITextPartition::advance() {
    this->currentIndex++;
}


void UITextPartition::invalidate() {
    this->currentIndex = this->max_index;
}


size_t UITextPartition::index() const {
    return this->currentIndex;
}


size_t UITextPartition::size() const {
    return this->elements.size();
}


string UITextPartition::operator[](size_t index) const {
    return this->elements[index];
}
