//
//  ObjectAttributes.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ObjectAttributes
//
//  Created by mpuchkov on 2019-04-13. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ObjectAttributes_h
#define ObjectAttributes_h

#include "objects.hpp"
#include "ObjectData.h"


namespace objects {

    
/*!
 @class ObjectAttributes
 
 @brief Equipped objects affect character's attributes.
 
 Protocol for ObjectAttributes data class.
 */
class ObjectAttributes: public ObjectData<ObjectAttributes> {
public:
    
    ObjectAttributes() = default;
    virtual ~ObjectAttributes() = default;
    
    
    
    /* ObjectAttributes Protocol */
    
    virtual AttributeValue bonusHealth() const noexcept = 0;
    virtual AttributeValue bonusDamage() const noexcept = 0;
    
    
    
    /* ObjectData Protocol */
    
    virtual std::string toString() const noexcept = 0;
    virtual std::vector<std::string> toVector() const noexcept = 0;
    
};


} /* namespace objects */



//ObjectAttributes(unsigned int health, unsigned int damage);
//ObjectAttributes* operator+(const ObjectAttributes *&other) const;
//const unsigned int health;
//const unsigned int damage;

#endif /* ObjectAttributes_h */
