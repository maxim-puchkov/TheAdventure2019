//
//  UIText.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.UIText
//
//  Created by mpuchkov on 2019-03-25. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "UIText.h"


namespace ui {
namespace text {


/* Constructors */

UIText::UIText(const Text &source)
    : source(source)
{ }

UIText::UIText(const Text &source, std::size_t width)
    : source(source),
    width(width)
{ }




/* Change text style */

void UIText::format() {
    auto partition = this->partition(this->words());
    this->block = partition.block;
    this->block_length = partition.length;
}




/* Text */

Text UIText::sourceText() const {
    return this->source;
}

TextBlock UIText::sourceBlock() const {
    return this->block;
}










/* * *   Private   * * */

UITextPartition UIText::words() const {
    IStream stream(this->source);
    return UITextPartition({
        IStreamIterator{stream},
        IStreamIterator{}
    });
}


// !
TextLine UIText::nextLine(UITextPartition &partition) const {
    auto start = partition.index();
    if (partition[start].length() > this->width) {
        partition.invalidate();
        return EMPTY;
    }
    
    OStream stream;
    std::size_t length = 0;
    
    auto DEL = ui::text::styles::WS;
    std::size_t del_length = DEL.length();

    for (auto i = partition.index(); i < partition.max_index; i++) {
        Word word = partition[i];
        if (length + word.length() > this->width) {
            break;
        }

        if (i > start) {
            stream << DEL;
            length += del_length;
        }

        stream << word;
        length += word.length();
        partition.advance();
    }

    return stream.str();
}


Result UIText::partition(UITextPartition &&partition) const {
    TextBlock block;
    std::size_t width = this->width;
    std::size_t length = 0;
    
    while (!partition.done()) {
        TextLine line = this->nextLine(partition);
        block.push_back(line);
        length += line.size();
    }
    
    return {block, width, length};
}


} /* namespace text */
} /* namespace ui */
