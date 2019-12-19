//
//  Description.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Description.h"


namespace items {

inline namespace description_defaults {
    const Text EMPTY;
    const Text DELIMITER = ", ";
    const Text WS = " ";
    const size_t LINE_WIDTH = ui::text::WIDTH;
}


/* Constructors */

Description::Description()
: shortdesc(EMPTY), longdesc({EMPTY}), source(EMPTY), width(LINE_WIDTH)
{ }


Description::Description(const Text &source)
: source(source, LINE_WIDTH), width(LINE_WIDTH) {
    this->init();
}


Description::Description(const vector<Text> &source)
: longdesc(source), source(toString()) {
    this->shortdesc = this->cut();
    this->width = this->lineWidth();
}


Description::Description(const Text &source, uint16_t lineWidth)
: source(source, lineWidth), width(lineWidth) {
    this->init();
}





/* ObjectData Protocol */

string Description::toString() const noexcept {
    return this->full();
}


vector<string> Description::toVector() const noexcept {
    return this->longdesc;
}





/* Description properties */

void Description::setWidth(uint16_t width) {
    this->width = width;
}


void Description::setBrief(const Text &description) {
    this->shortdesc = description;
}


void Description::setFull(const vector<Text> &description) {
    this->longdesc = description;
}


void Description::clear() {
    this->shortdesc.empty();
    this->longdesc.empty();
}






/* Retrieval */

Text Description::brief() const {
    return this->shortdesc;
}


Text Description::full() const {
    ostringstream stream{""};
    
    auto iterator = this->longdesc.cbegin();
    stream << *iterator;
    
    auto end = this->longdesc.cend();
    for (iterator = iterator + 1; iterator < end; iterator++) {
        stream << '\n' << *iterator;
    }
    
    return stream.str();
}


size_t Description::lineCount() const {
    return this->longdesc.size();
}


size_t Description::lineWidth() const {
    return this->shortdesc.size();
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
    
    if (this->source.data() == EMPTY) {
        this->longdesc = {};
        this->shortdesc = EMPTY;
        return;
    }
    
    this->source.format();
    
    vector<Text> lines = this->source.arrangedSource();
    this->longdesc = lines;
    
    this->shortdesc = this->cut();
}


Text Description::cut() const {
    return this->longdesc[0];
}


} /* namespace items */
