//
//  ItemConstructor.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemConstructor.h"


ItemConstructor::ItemConstructor()
{ }


ItemConstructor::~ItemConstructor()
{ }


Item ItemConstructor::create() {
    return Item(id, keywords, description, extras);
}


void ItemConstructor::reset() {
    this->clearAll();
}


void ItemConstructor::setKeywords(const KeywordSet &keywords) {
    this->keywords = keywords;
}


void ItemConstructor::setDescription(const Description &description) {
    //this->description = Description(description, LINE_WIDTH, SHORT_DESCRIPTION_WIDTH);
}


void ItemConstructor::clearAll() {
    this->keywords.clear();
    this->description.clear();
    this->extras.clear();
}


//Identifier ItemConstructor::nextIdentifier() {
//    return this->unique_identifiers.generate();
//}


