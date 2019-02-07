//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"

Item::Item(const string &description)
: description(description) {
    this->id = Identifiers::uid();
}


Item::Item(const Item &other)
: description(std::move(other.description)) {
    this->id = other.id;
}


Item::Item(Item &&item)
: description(std::move(item.description)) {
    this->id = item.id;
}


unsigned long Item::getId() const {
    return this->id;
}


string Item::getDescription() const {
    return this->description;
}


Item& Item::operator=(Item &&other) noexcept {
    this->id = std::move(other.id);
    this->description = std::move(other.description);
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

