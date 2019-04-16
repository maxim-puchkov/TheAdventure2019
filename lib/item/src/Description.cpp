//
//  Description.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Description.h"


namespace items {

const Text Description::DEFAULT_DESCRIPTION_TEXT = "No description.";
const Description Description::DEFAULT_INSTANCE = Description(DEFAULT_DESCRIPTION_TEXT);

/* Constructors */

Description::Description()
: shortdesc(EMPTY), longdesc({EMPTY}), width(LINE_WIDTH), source(EMPTY)
{ }


Description::Description(const Text &source)
: width(LINE_WIDTH), source(source, LINE_WIDTH) {
    this->init();
}


Description::Description(const TextBlock &block)
: longdesc(block), source(toString()) {
    this->shortdesc = this->cut();
    this->width = this->lineWidth();
}


Description::Description(const Text &source, std::size_t width)
: width(width), source(source, width) {
    this->init();
}





/* ObjectData Protocol */

//Description& Description::reset() noexcept {
//    return DEFAULT_DESCRIPTION;
//}


std::size_t Description::size() const noexcept {
    return (this->lineCount() * this->lineWidth());
}


string Description::toString() const noexcept {
    return this->full();
}


vector<string> Description::toVector() const noexcept {
    return this->longdesc;
}





/* Description properties */

void Description::setWidth(std::size_t width) {
    this->width = width;
}


void Description::setBrief(const Text &description) {
    this->shortdesc = description;
}


void Description::setFull(const TextBlock &description) {
    this->longdesc = description;
}




/* Retrieval */

Text Description::brief() const {
    return this->shortdesc;
}

Text Description::full() const {
    data_ostream stream;
    auto iterator = this->longdesc.cbegin();
    stream << *iterator;
    
    auto end = this->longdesc.cend();
    auto DEL = ui::text::styles::NL;
    for (iterator++; iterator < end; iterator++) {
        stream << DEL << *iterator;
    }
    
    return stream.str();
}


std::size_t Description::lineCount() const {
    return this->longdesc.size();
}

std::size_t Description::lineWidth() const {
    return this->shortdesc.size();
}






/* Operators */

bool Description::operator==(Description &other) const {
    return ((this->longdesc == other.longdesc) && (this->shortdesc == other.shortdesc));
}

bool Description::operator==(const Description &other) const {
    return ((this->longdesc == other.longdesc) && (this->shortdesc == other.shortdesc));
}


TextLine& Description::operator[](std::size_t index) {
    return this->longdesc[index];
}

TextLine Description::operator[](std::size_t index) const {
    return this->longdesc[index];
}







/* * *   Private   * * */

void Description::init() {
    
//    if (this->source.data() == EMPTY) {
//        this->longdesc = {};
//        this->shortdesc = EMPTY;
//        return;
//    }
    if (!this->validate()) { return; }
    
    this->source.format();
    TextBlock lines = this->source.sourceBlock();

    this->shortdesc = lines[0];
    this->longdesc = lines;
}


void Description::clear() noexcept {
    this->shortdesc.empty();
    this->longdesc.empty();
}


Description Description::default_data_instance() const noexcept {
    return Description::DEFAULT_INSTANCE;
}


bool Description::validate() const noexcept {
    bool valid = (this->source.sourceText() != EMPTY);
    if (!valid) {
        // this->longdesc = {};
        (const_cast<Description *>(this))->longdesc = {};
        (const_cast<Description *>(this))->shortdesc = EMPTY;
        // this->shortdesc = EMPTY;
    }
    return valid;
}











Text Description::cut() const {
    return this->longdesc[0];
}


} /* namespace items */
