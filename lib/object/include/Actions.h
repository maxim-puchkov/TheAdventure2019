//
//  Actions.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Actions
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Actions_h
#define Actions_h

#include <map>

/*
 @class Actions
 @brief Defines action reference, for any
           custom action key or its alias
 */
template<typename KeyType, typename RefType>
struct CustomActions {
public:
    CustomActions()
    : map({})
    { }
private:
    std::map<KeyType, RefType> map;
    KeyType key;
    RefType reference;
};

#endif /* Actions_h */
