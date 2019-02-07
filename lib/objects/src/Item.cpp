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


string Item::getDescription() {
    return this->description;
}


Item& Item::operator=(Item &&item) noexcept {
    this->id = std::move(item.id);
    this->description = std::move(item.description);
    return *this;
}
