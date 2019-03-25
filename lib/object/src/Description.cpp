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
    const string EMPTY = "";
    const uint16_t LINE_WIDTH = 5;
}


Description::Description()
: shortdesc(EMPTY), longdesc({EMPTY}), width(LINE_WIDTH)
{ }


Description::Description(const Text &source)
: source(source), width(LINE_WIDTH) {
    this->reformat();
    
    
    //this->reformat(source, lineWidth);
}


Description::Description(const Text &source, uint16_t lineWidth)
: source(source), width(lineWidth) {
    this->reformat();
    //this->reformat(source, lineWidth);
}




/* * * *  < Deprecated * * * */

//Description::Description(const string &desc)
//: shortdesc(desc)
//{ }
//
//Description::Description(const string &shortdesc, const vector<string> &longdesc)
//: shortdesc(shortdesc), longdesc(longdesc)
//{ }
//
//Description::Description(objects::Text description);

/* * * * Deprecated > * * * */






void Description::clear() {
    this->shortdesc.empty();
    this->longdesc.empty();
}


string Description::brief() const {
    return this->shortdesc;
}


vector<string> Description::full() const {
    return this->longdesc;
}

bool Description::operator==(Description &other) const {
    return (this->source == other.source);
}

bool Description::operator==(const Description &other) const {
    return (this->source == other.source);
}



/* Private */

vector<string> Description::textWords() const {
    std::stringstream ss(this->source);
    std::istream_iterator<string> begin{ss};
    std::istream_iterator<string> end{};
    return {begin, end};
}
