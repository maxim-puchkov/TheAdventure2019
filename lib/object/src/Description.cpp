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





// Constructors

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





//

void Description::setWidth(uint16_t width) {
    this->width = width;
}

/// Formats description according to line width
void Description::reformat() {
    
    debug::print("Source:", source);
    
    
    debug::print("All words -> ");
    auto words = this->textWords();
    for (auto &line : longdesc) {
        debug::print("Line: ", line);
    }
    debug::print("<- All words end");
    
    
    debug::print("All lines ->");
    auto longdesc = this->partition(words);
    for (auto &line : longdesc) {
        debug::print("Line: ", line);
    }
    debug::print("<- All lines end");
    
}

void Description::clear() {
    this->shortdesc.empty();
    this->longdesc.empty();
}




//




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


bool Description::operator==(Description &other) const {
    return (this->source == other.source);
}


bool Description::operator==(const Description &other) const {
    return (this->source == other.source);
}










/* Private */

vector<string> Description::textWords() const {
    std::stringstream ss(this->source);
    return {std::istream_iterator<string>{ss}, std::istream_iterator<string>{}};
}


Text Description::toString(vector<string> &&words) const {
    std::stringstream line(words[0]);
    const char WS = ' ';
    const unsigned long SIZE = words.size();
    
    for (unsigned long i = 1; i < SIZE; i++) {
        line << WS << words[i];
    }
    
    return line.str();
}


vector<Text> Description::partition(const vector<Text> &words) const {
    
    vector<Text> lines;
    
    
    //std::stringstream line("");
    vector<string> line;
    unsigned short lineLength = 0;
    
    
    
    for (auto &word : words) {
        auto wordLength = word.size();
        
        // Go to next line if cannot fit
        if ((lineLength + wordLength) > this->width) {
            //lines.push_back(line.str());
            Text fullLine = this->toString(std::move(line));
            line.clear();
            lineLength = 0;
            
            lines.push_back(fullLine);
        }
        
        line.push_back(word);
        lineLength += (wordLength + 1);
    }
    
    return lines;
    
}
