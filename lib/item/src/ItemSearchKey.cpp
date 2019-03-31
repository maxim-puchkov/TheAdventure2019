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

//    
//bool ItemSearchKey::operator<(ItemSearchKey &other) const {
//    return this->index < other.index;
//}
//bool ItemSearchKey::operator<(const ItemSearchKey &other) const {
//    return this->index < other.index;
//}

bool ItemSearchKey::operator==(ItemSearchKey &other) const {
    return ((this->id == other.id) || (this->keywords == other.keywords));
}

bool ItemSearchKey::operator==(const ItemSearchKey &other) const {
    return ((this->id == other.id) || (this->keywords == other.keywords));
}


} /* namespace items */






namespace std {


size_t hash<ItemSearchKey>::operator()(const ItemSearchKey &key) const {
    return hash<items::Identifier>{}(key.id);
}


} /* namespace std */
