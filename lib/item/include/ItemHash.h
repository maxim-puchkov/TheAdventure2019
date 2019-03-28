//
//  ItemHash.h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.ItemHash
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ItemHash_h
#define ItemHash_h


namespace std {

using items::Item;


/*!
 @struct hash
 @discussion Item's hash function
 */
template<>
struct hash<Item> {
    size_t operator()(const Item &item) const;
};


}

#endif /* ItemHash_h */
