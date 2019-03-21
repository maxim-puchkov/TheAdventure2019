//
//  Object.h
//  Objects
//  com.maximpuchkov.Objects.Objects.Object
//
//  Package:             Objects
//  Project:             Objects
//  Workspace:           Objects
//  Organization:        maximpuchkov
//  Prefix:              com
//
//  Author:              Maxim Puchkov (mpuchkov@sfu.ca)
//  Full username:       admin
//  Created on:          2019-03-15 at 4:07 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//


#ifndef Object_h
#define Object_h

#include <string>
#include <vector>
#include <functional>
#include <cstdint>
#include <sstream>
#include <unordered_set>

#include "ObjectDataType.h"
#include "KeywordSet.h"
#include "Description.h"


namespace objects {
using namespace data;

/**
    @class Object
 
    @brief Instance within a game that can be
           uniquely identified and interacted with
 */
class Object {
public:
    
    virtual ~Object()
    { }
    
    /// Retrieve object ID
    virtual Identifier id() const = 0;
    
    
    /// Examine an Extra attribute of an item
    virtual bool examine(const Key &keyword) const = 0;
    
    
    /// Display detailed info
    virtual Text details() const = 0;
    
    
    /// Display item's first keyword
    virtual Key brief() const = 0;
    
};

} /* namespace objects */


#endif /* Object_h */
