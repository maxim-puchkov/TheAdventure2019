//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"
using namespace objects;

#include "DebugToolset.h"



ItemBuilder::ItemBuilder()
: ready(true), keywords(KeywordSet()), description(Description()), actions(Actions()) {
    
}


//ItemBuilder::~ItemBuilder()
//{ }


Item ItemBuilder::create() {
    //return Item(id, keywords, description, extras);
    
    Item item(id, keywords, description, actions);
    // ...
    return item;
}


void ItemBuilder::reset() {
     this->clearAll();
}


//void ItemBuilder::setKeywords(const KeywordSet &keywords) {
//    this->keywords = keywords;
//}


//void ItemBuilder::setDescription(const Description &description) {
//    //this->description = Description(description, LINE_WIDTH, SHORT_DESCRIPTION_WIDTH);
//}


void ItemBuilder::clearAll() {
    this->keywords.clear();
    this->description.clear();
    this->actions.clear();
}


//Identifier ItemBuilder::nextIdentifier() {
//    return this->unique_identifiers.generate();
//}
