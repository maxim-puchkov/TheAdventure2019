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
#include "ObjectData.h"
#include "ObjectAttributes.h"

namespace objects {


/*!
 @class Object
 
 @brief Interactable game object interface
 
 Every object has Keywords, Description, and Actions.
 Every object can be converted to string.
 */
class Object {
public:
    
    /* Object Interface */
    
    /*! Very short description of this object */
    virtual Text info() const = 0;
    
    /*! Full and detailed description of this object that may span multiple lines */
    virtual Text details() const = 0;
    
    /*! Examine an action to see its description */
    virtual Text examine(const Text &keyword) const = 0;
    
    /*! Represent this object and its properties as text */
    virtual Text toText() const = 0;

    
    

    
    /*! Check if object has additional actions */
    virtual bool isInteractable() const = 0;
    
    /*! Check if object allowed to be equipped */
    virtual bool isEquipable() const = 0;
    
    
    
    
    /*! Object's virtual base destructor */
    virtual ~Object() noexcept = default;
    
    
    
    
    /*! Unique identifier assigned to this object */
    [[deprecated]] virtual ObjectIdentifier identifier() const = 0;
};


} /* namespace objects */

#endif /* Object_h */
