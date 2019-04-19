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
namespace text {


/* Constructors */

UITextPartition::UITextPartition(TextBlock &&block) noexcept
    : max_index(block.size()),
    lines(std::move(block))
{ }






/* Partitioning state */

bool UITextPartition::done() const {
    return (this->currentIndex >= this->max_index);
}


std::size_t UITextPartition::index() const {
    return this->currentIndex;
}


std::size_t UITextPartition::length() const {
    return this->lines.size();
}





/* Mutable current index control */

Word UITextPartition::next() {
    Word word = this->lines.at(this->currentIndex);
    this->advance();
    return word;
}


void UITextPartition::advance() {
    this->currentIndex++;
}


void UITextPartition::invalidate() {
    this->currentIndex = this->max_index;
}





/* Operators */

UITextPartition& UITextPartition::operator++() {
    this->advance();
    return *this;
}

UITextPartition UITextPartition::operator++(int) {
    UITextPartition advanced(*this);
    operator++();
    return advanced;
}


TextLine& UITextPartition::operator[](std::size_t index) {
    return this->lines[index];
}

const TextLine& UITextPartition::operator[](std::size_t index) const {
    return this->lines[index];
}


} /* namespace text */
} /* namespace ui */
