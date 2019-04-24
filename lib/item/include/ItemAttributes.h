//
//  ItemAttributes.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ItemAttributes
//
//  Created by mpuchkov on 2019-04-13. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ItemAttributes_h
#define ItemAttributes_h

#include "items.hpp"

#include "ObjectAttributes.h"


namespace items {

inline namespace defaults {
    const AttributeValue NO_VALUE = 0;
}




class ItemAttributes: public objects::ObjectData<ItemAttributes> {
public:
    
    ItemAttributes()
        : ItemAttributes(NO_VALUE, NO_VALUE)
    { }
    
    ItemAttributes(const ItemAttributes &) = default;
    
    ItemAttributes(std::initializer_list<AttributeValue> list)
    // : health(values[0]), damage(values[1])
    { }
    
    ItemAttributes(AttributeValue health, AttributeValue damage)
        : health(health), damage(damage)
    { }
    
    
    
    std::size_t size() const noexcept override;
    
    /*! Total change in attribute points resulting from equipping this item */
    AttributeValue total() const noexcept;
    
    /*! Item is equipable if it affects character's attributes */
    bool isEquipable() const;
    
    AttributeValue bonusHealth() const noexcept;
    AttributeValue bonusDamage() const noexcept;
    
    std::string toString() const noexcept override;
    std::vector<std::string> toVector() const noexcept override;
    
    ItemAttributes& operator=(ItemAttributes &&) noexcept;
    ItemAttributes& operator=(const ItemAttributes &) noexcept;
    
private:
    
    AttributeValue health;
    AttributeValue damage;
    
    void clear() noexcept override;
    
};




    
    // cpp


std::size_t ItemAttributes::size() const noexcept {
    return this->total();
}

/*! Total change in attribute points resulting from equipping this item */
AttributeValue ItemAttributes::total() const noexcept {
    return (this->health + this->damage);
}

/*! Item is equipable if it affects character's attributes */
bool ItemAttributes::isEquipable() const {
    return (this->total() != 0);
}


AttributeValue ItemAttributes::bonusHealth() const noexcept {
    return this->health;
}

AttributeValue ItemAttributes::bonusDamage() const noexcept {
    return this->damage;
}


std::string ItemAttributes::toString() const noexcept {
    return {
        "(health: " +
        std::to_string(this->health) +
        ", damage: " +
        std::to_string(this->damage) +
        ")"
    };
}

std::vector<std::string> ItemAttributes::toVector() const noexcept {
    return {
        this->toString()
    };
}


ItemAttributes& ItemAttributes::operator=(ItemAttributes &&other) noexcept {
    this->health = std::move(other.health);
    this->damage = std::move(other.damage);
    return *this;
}

ItemAttributes& ItemAttributes::operator=(const ItemAttributes &other) noexcept {
    this->health = other.health;
    this->damage = other.damage;
    return *this;
}




/* */

void ItemAttributes::clear() noexcept {
    this->health = 0;
    this->damage = 0;
}


} /* namespace items */

#endif /* ItemAttributes_h */
