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


/* Constructors */

UIText::UIText(const string &source)
: source(source), width(WIDTH) {
    this->lines.reserve(RESERVE);
}


UIText::UIText(const string &source, size_t width)
: source(source), width(width) {
    this->lines.reserve(RESERVE);
}





/* Change text style */

void UIText::format() {
    UITextPartitionResult result = this->partition(this->words());
    this->lines = result.content;
    this->length = result.length;
}




/* Text */

string UIText::data() const {
    return this->source;
}


vector<string> UIText::arrangedSource() const {
    return this->lines;
}










/* * *   Private   * * */

UITextPartition UIText::words() const {
    std::istringstream stream(this->source);
    return UITextPartition({std::istream_iterator<string>{stream},
        std::istream_iterator<string>{}});
}

string UIText::nextLine(UITextPartition &partition) const {

    const char delimiter = ' ';
    const unsigned long start = partition.index();

    std::ostringstream output("");
    unsigned int length = 0;

    if (partition[start].length() > this->width) {
        partition.invalidate();
        return "";
    }

    for (unsigned long i = partition.index(); i < partition.max_index; i++) {
        string word = partition[i];
        if (length + word.length() > this->width) {
            break;
        }

        if (i > start) {
            output << delimiter;
            length += 1;
        }

        output << word;
        length += word.size();
        partition.advance();
    }

    return output.str();
    
}

UITextPartitionResult UIText::partition(UITextPartition &&partition) const {
    vector<string> lines;
    size_t length = 0;
    
    while (!partition.done()) {
        string line = this->nextLine(partition);
        lines.push_back(line);
        length += line.size();
    }
    
    UITextPartitionResult result({lines, length});
    return result;
}


} /* namespace ui */
