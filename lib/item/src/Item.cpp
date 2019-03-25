//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"
using namespace objects;


Item::Item(Identifier id,
           const KeywordSet &keywords,
           const Description &description,
           const Actions &actions)
: itemID(id), keywords(keywords), description(description), actions(actions)
{ }

// Item::Item() { }
// Item::~Item() { }

Identifier Item::id() const {
    return this->itemID;
}

Key Item::brief() const {
    return this->keywords.first();
}


Text Item::display() const {
    return this->keywords.asString();
}


bool Item::hasKeyword(const Key &keyword) const {
    return this->keywords.contains(keyword);
}


Text Item::examine(const Key &keyword) const {
    
    // .....
    return "callee: Item::examine(const Key&)";
    
}



Item& Item::operator=(const Item &other) {
    this->itemID = other.id();
    this->keywords = other.keywords;
    this->description = other.description;
    this->actions = other.actions;
    return *this;
}

Item& Item::operator=(Item &other) {
    this->itemID = other.id();
    this->keywords = other.keywords;
    this->description = other.description;
    this->actions = other.actions;
    return *this;
}

std::size_t std::hash<Item>::operator()(const Item &item) const {
    return std::hash<unsigned long>{}(item.id());
}
