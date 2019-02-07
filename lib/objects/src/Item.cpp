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


Item::Item(Item &&item)
: description(std::move(item.description)) {
    this->id = item.id;
}


unsigned long Item::getId() const {
    return this->id;
}


string Item::getDescription() {
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

