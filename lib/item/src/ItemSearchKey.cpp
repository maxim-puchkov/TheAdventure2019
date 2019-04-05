//
//  ItemSearchKey.cpp
//  Objects: Objects
//  com.maximpuchkov.Objects.Objects.ItemSearchKey
//
//  Created by mpuchkov on 2019-03-29. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "ItemSearchKey.h"

namespace items {


ItemSearchKey::ItemSearchKey(ItemIdentifier id)
: id(id), keywords(Keywords{})
{ }

ItemSearchKey::ItemSearchKey(const Keywords &keywords)
: id(0), keywords(keywords)
{ }

ItemSearchKey::ItemSearchKey(ItemIdentifier id, const Keywords &keywords)
: id(id), keywords(keywords)
{ }

ItemSearchKey::ItemSearchKey(const Item &item)
: id(item.id), keywords(item.keywords)
{ }

ItemSearchKey::ItemSearchKey(const ItemSearchKey &key)
: id(key.id), keywords(key.keywords)
{ }


bool ItemSearchKey::operator==(ItemSearchKey &other) const {
    return ((this->id == other.id) || (this->keywords == other.keywords));
}

bool ItemSearchKey::operator==(const ItemSearchKey &other) const {
    return ((this->id == other.id) || (this->keywords == other.keywords));
}


string ItemSearchKey::toString() const noexcept {
    ostringstream stream{""};
    stream << "(id: " << id << ", keywords: " << keywords.toString() << ")";
    return stream.str();
}


} /* namespace items */






namespace std {


size_t hash<ItemSearchKey>::operator()(const ItemSearchKey &key) const {
    return hash<items::ItemIdentifier>{}(key.id);
}


} /* namespace std */
