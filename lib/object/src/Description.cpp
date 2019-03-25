//
//  Description.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Description.h"

using namespace objects;

inline namespace defaults {
    const Text EMPTY = "";
    const Text DELIMITER = ", ";
    const Text WS = " ";
    const uint16_t LINE_WIDTH = 5;
}





/* Constructors */

Description::Description()
: source(EMPTY), shortdesc(EMPTY), longdesc({EMPTY}), width(LINE_WIDTH)
{ }


Description::Description(const Text &source)
: source(source, LINE_WIDTH), width(LINE_WIDTH) {
    this->init();
}


Description::Description(const Text &source, uint16_t lineWidth)
: source(source, lineWidth), width(lineWidth) {
    this->init();
}





/* Description properties */

void Description::setWidth(uint16_t width) {
    this->width = width;
}


// void Description::reformat() { }


void Description::clear() {
    this->shortdesc.empty();
    this->longdesc.empty();
}






/* Retrieval */

Text Description::brief() const {
    return this->shortdesc;
}


Text Description::full() const {
    std::stringstream ss{""};
    for (auto &line : this->longdesc) {
        ss << line << '\n';
    }
    return ss.str();
}

size_t Description::lineCount() const {
    return this->longdesc.size();
}






/* Operators */

bool Description::operator==(Description &other) const {
    return (this->source.data() == other.source.data());
}

bool Description::operator==(const Description &other) const {
    return (this->source.data() == other.source.data());
}


Text Description::operator[](size_t index) {
    return this->longdesc[index];
}

Text Description::operator[](size_t index) const {
    return this->longdesc[index];
}







/* * *   Private   * * */

void Description::init() {
    this->source.format();
    Lines lines = this->source.arrangedSource();
    this->shortdesc = lines[0];
    this->longdesc = lines;
}

//TextPartitionUnits Description::textWords() const {
//    std::stringstream ss(this->source);
//    return TextPartitionUnits({std::istream_iterator<string>{ss},
//        std::istream_iterator<string>{}});
//}
//
//
//Text Description::toString(vector<string> &&words) const {
//    std::stringstream line(words[0]);
//    const unsigned long SIZE = words.size();
//
//    for (unsigned long i = 1; i < SIZE; i++) {
//        line << WS << words[i];
//    }
//
//    return line.str();
//}
//
//
//Text Description::nextLine(TextPartitionUnits &unit) const {
//
//    const Text delimiter = WS;
//    const unsigned long start = unit.index;
//
//    std::stringstream output("");
//    unsigned int length = 0;
//
//    if (unit[start].length() > this->width) {
//        unit.index = unit.max_index;
//        return EMPTY;
//    }
//
//    for (unsigned long i = unit.index; i < unit.max_index; i++) {
//        Text word = unit[i];
//        if (length + word.length() > this->width) {
//            break;
//        }
//
//        if (i > start) {
//            output << delimiter;
//            length += 1;
//        }
//
//        output << word;
//        length += word.size();
//        unit.index++;
//    }
//
//    return output.str();
//}
//
//
//TextPartition Description::partition(TextPartitionUnits &&words) const {
//
//    TextPartitionUnits unit(std::move(words));
//
//    Lines lines;
//    lines.reserve(RESERVE);
//
//    size_t length = 0;
//    while (!unit.done()) {
//        Text line = this->nextLine(unit);
//        std::cout << "Scanning lines: " << line << '\n';
//        lines.push_back(line);
//        length += line.size();
//    }
//
//    TextPartition output({lines, length});
//
//
//    for (auto &l : lines) {
//        std::cout << "Line: '" << l << "'\n";
//    }
//    std::cout << "Line sz = " << lines.size() << '\n';
//    std::cout << "Length = " << length << '\n';
//
//
//    return output; //  {{""}, 0};
//
//}
