//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"
#include <iostream>


Item::Item() {
    this->id = Identifiers::uid();
}


Item::Item(const string &shortDescription)
: shortDescription(shortDescription), longDescription(shortDescription) {
    this->id = Identifiers::uid();
}


Item::Item(const string &shortDescription, const string &longDescription)
: shortDescription(shortDescription), longDescription(shortDescription) {
    //Item();
}


Item::Item(const Item &other)
: shortDescription(std::move(other.shortDescription)),
longDescription(std::move(other.longDescription)) {
    this->id = other.id;
}


Item::Item(Item &&other)
: shortDescription(std::move(other.shortDescription)),
longDescription(std::move(other.longDescription)) {
    this->id = other.id;
}


Item::~Item()
{ }


unsigned long Item::getId() const {
    return this->id;
}


string Item::getShortDescription() const {
    return this->shortDescription;
}


string Item::getLongDescription() const {
    return this->longDescription;
}


void Item::setLongDescription(string &&longDescription) {
    this->longDescription = std::move(longDescription);
}


Item& Item::operator=(Item &&other) noexcept {
    this->id = std::move(other.id);
    this->shortDescription = std::move(other.shortDescription);
    return *this;
}


bool Item::operator==(Item &other) const {
    return this->id == other.id;
}


bool Item::operator==(const Item &other) const {
    return this->id == other.id;
}


size_t std::hash<Item>::operator()(const Item &item) const {
    return std::hash<unsigned long>{}(item.getId());
}

