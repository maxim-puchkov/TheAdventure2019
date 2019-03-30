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


/*!
 @class Object
 
 @brief Interactable game object interface
 
 Every object has Keywords, Description, and Actions.
 */
class Object {
public:
    
    /*! Object constructor */
    Object();
    
    /*! Object destructor */
    virtual ~Object();
    
    
    
    
    
    /* Object Interface */
    
    /*! Unique identifier assigned to this object */
    virtual Identifier identifier() const = 0;
    
    /*! Display item's short description */
    virtual Text brief() const = 0;
    
    /*! Represent this object as string */
    virtual Text toString() const = 0;
    
    /*! Examine an action to see its description */
    virtual Text examine(const Key &keyword) const = 0;
    
};


} /* namespace objects */

#endif /* Object_h */
