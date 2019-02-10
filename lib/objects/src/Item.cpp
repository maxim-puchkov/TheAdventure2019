//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"
#include <iostream>

Item::Item(const string &shortDescription)
: shortDescription(shortDescription) {
    this->id = Identifiers::uid();
}


Item::Item(const Item &other)
: shortDescription(std::move(other.shortDescription)) {
    this->id = other.id;
}


Item::Item(Item &&item)
: shortDescription(std::move(item.shortDescription)) {
    this->id = item.id;
}


unsigned long Item::getId() const {
    return this->id;
}


string Item::getShortDescription() const {
    std::cout << "ITEM S DESC\n";
    return this->shortDescription;
}


string Item::getLongDescription() const {
    std::cout << "ITEM L DESC\n";
    return this->longDescription;
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


size_t std::hash<Item>::operator()(const Item& item) const {
    return std::hash<unsigned long>{}(item.getId());
}

