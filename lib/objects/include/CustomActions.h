//
//  CustomActions.h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.CustomActions
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef CustomActions_h
#define CustomActions_h

#include <string>
#include <map>


/**
 @class CustomActions
 
 @brief Defines action reference, for any
           custom action key or its alias
 
 @ignore
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


#endif /* CustomActions_h */
