//
//  Collection.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Collection.h"

Collection::Collection(const string &description)
: shortDescription(description)
{ }


Collection::Collection(Collection &&c)
: shortDescription(std::move(c.shortDescription)), items(std::move(c.items))
{ }


Collection::~Collection()
{ }


unordered_set<Item> Collection::getItems() const {
    return this->items;
}


string Collection::getShortDescription() const {
    std::ostringstream oss;
    oss << "Bag: " << this->shortDescription << std::endl;
    if (this->items.empty()) {
        oss << "<empty>" << std::endl;
        return oss.str();
    }
    
    for (auto& item : this->items) {
        oss << item.getShortDescription() << std::endl;
    }
    return oss.str();
}


string Collection::getLongDescription() const {
    return "long desc";
}


void Collection::setLimit(unsigned int limit) {
    this->limit = limit;
}


bool Collection::add(Item &&item) {
    return (!this->isFull() && (this->items.insert(std::move(item))).second);
}


bool Collection::remove(Item &&item) {
    return (this->items.erase(std::move(item)) == 1);
}


Collection& Collection::operator=(Collection &&c) noexcept {
    this->items = std::move(c.items);
    return *this;
    }


bool Collection::isLimited() {
    return (this->limit != NO_LIMIT);
}


bool Collection::isFull() {
    return (this->isLimited() && (this->items.size() == this->limit));
    }
