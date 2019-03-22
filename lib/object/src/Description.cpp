//
//  Description.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Description.h"
using objects::Description;


Description::Description()
: shortdesc(EMPTY), longdesc({EMPTY})
{ }


Description::Description(const string &shortdesc, const vector<string> &longdesc)
: shortdesc(shortdesc), longdesc(longdesc)
{ }


// Description::Description(objects::Text description);


void Description::clear() {
    this->shortdesc.empty();
    this->longdesc.empty();
}


string Description::getShort() const {
    return this->shortdesc;
}


vector<string> Description::getLong() const {
    return this->longdesc;
}
