//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"


ItemBuilder::ItemBuilder()
{ }


ItemBuilder::~ItemBuilder()
{ }


Item ItemBuilder::create() {
    return Item(id, keywords, description, extras);
}


void ItemBuilder::reset() {
    this->clearAll();
}


void ItemBuilder::setKeywords(const KeywordSet &keywords) {
    this->keywords = keywords;
}


void ItemBuilder::setDescription(const Description &description) {
    //this->description = Description(description, LINE_WIDTH, SHORT_DESCRIPTION_WIDTH);
}


void ItemBuilder::clearAll() {
    this->keywords.clear();
    this->description.clear();
    this->extras.clear();
}


//Identifier ItemBuilder::nextIdentifier() {
//    return this->unique_identifiers.generate();
//}


