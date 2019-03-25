//
//  Object.h
//  adventure2019: Object
//  com.maximpuchkov.Faworki.adventure2019.Object
//
//  Created by mpuchkov on 2019-03-15 at 4:07 PM. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include "objects.hpp"

#include "Keywords.h"
#include "Description.h"
#include "Actions.h"

namespace objects {


/**
    @class Object
 
    @brief Instance within a game that can be
           uniquely identified and interacted with
 */
class Object {
public:
    
    Object();
    
    ~Object();
    
    /// Retrieve object ID
    virtual Identifier id() const = 0;
    
    
    /// Display item's short description
    virtual Key brief() const = 0;
    
    
    /// Represent this object as formatted text
    virtual Text display() const = 0;
    
    
    /// Examine an action to see its description
    virtual Text examine(const Key &keyword) const = 0;
    
};


} /* namespace objects */

#endif /* Object_h */
