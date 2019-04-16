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
    
ItemSearchKey::ItemSearchKey(Item const *item)
: ItemSearchKey(item->id, item->keywords)
{ }

ItemSearchKey::ItemSearchKey(const Item &item)
: ItemSearchKey(item.id, item.keywords)
{ }

ItemSearchKey::ItemSearchKey(const ItemSearchKey &search_key)
: ItemSearchKey(search_key.id, search_key.keywords)
{ }





std::string ItemSearchKey::toString() const noexcept {
    data_ostream stream;
    stream << "(id: " << id << ", keywords: " << keywords.toString() << ")";
    return stream.str();
}





bool ItemSearchKey::operator==(ItemSearchKey &other) const {
    return ((this->id == other.id) || (this->keywords == other.keywords));
}

bool ItemSearchKey::operator==(const ItemSearchKey &other) const {
    return ((this->id == other.id) || (this->keywords == other.keywords));
}


} /* namespace items */






namespace std {


size_t hash<ItemSearchKey>::operator()(const ItemSearchKey &key) const {
    return hash<items::ItemIdentifier>{}(key.id);
}


} /* namespace std */
