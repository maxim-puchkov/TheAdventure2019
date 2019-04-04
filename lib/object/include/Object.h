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


namespace objects {

/*! Type aliases */
inline namespace typenames {
    using ObjectIdentifier = uint64_t;
    using Text = string;
} /* namespace typenames */


/*!
 @class Object
 
 @brief Interactable game object interface
 
 Every object has Keywords, Description, and Actions.
 Every object can be converted to string.
 */
class Object {
public:
    
    
    /*! Object constructor */
    Object() = default;
    
    /*! Object destructor */
    virtual ~Object() = default;
    
    
    
    
    
    /* Object Interface */
    
    /*! Unique identifier assigned to this object */
    virtual ObjectIdentifier identifier() const = 0;
    
    
    /*! Display item's short description */
    virtual Text brief() const = 0;
    
    
    /*! Examine an action to see its description */
    virtual Text examine(const Text &keyword) const = 0;
    
    
    /*! Represent this object as string */
    virtual Text toString() const = 0;
    
    
    /*! Check if object has additional actions */
    virtual bool isInteractable() const = 0;
    
    
};


} /* namespace objects */

#endif /* Object_h */
