//
//  ItemSearchKey.h
//  Objects: Objects
//  com.maximpuchkov.Objects.Objects.ItemSearchKey
//
//  Created by mpuchkov on 2019-03-29. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ItemSearchKey_h
#define ItemSearchKey_h

#include "items.hpp"
#include "Item.h"

namespace items {


class ItemSearchKey {
public:
    
    const ItemIdentifier id;
    const Keywords keywords;
    
    
    ItemSearchKey(ItemIdentifier id);
    ItemSearchKey(const Keywords &keywords);
    ItemSearchKey(ItemIdentifier id, const Keywords &keywords);
    ItemSearchKey(const Item &item);
    ItemSearchKey(const ItemSearchKey &key);
    
    
    bool operator==(ItemSearchKey &other) const;
    bool operator==(const ItemSearchKey &other) const;
    
    
    std::string toString() const noexcept;
    
};

    
} /* namespace items */





namespace std {

using items::ItemSearchKey;


/*!
 @struct hash
 @discussion Item's hash function
 
 @ignore
 */
template<>
struct hash<ItemSearchKey> {
    size_t operator()(const ItemSearchKey &key) const;
};


} /* namespace std */

#endif /* ItemSearchKey_h */
