//
//  ItemConstructor.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemConstructor.h"


ItemConstructor::ItemConstructor()
: unique_identifiers(identity::UUID())
{ }


ItemConstructor::~ItemConstructor()
{ }


Item ItemConstructor::create() {
    ObjectID id = this->nextUUID();
    return Item(id, keywords, description, extras);
}


void ItemConstructor::reset() {
    this->clearAll();
}


void ItemConstructor::setKeywords(const Keywords &keywords) {
    this->keywords = keywords;
}


void ItemConstructor::setDescription(const Text &description) {
    //this->description = ItemDescription(description, LINE_WIDTH, SHORT_DESCRIPTION_WIDTH);
}


void ItemConstructor::clearAll() {
    this->keywords.clear();
    this->description.clear();
    this->extras.clear();
}


ObjectID ItemConstructor::nextUUID() {
    return this->unique_identifiers.generate();
}


