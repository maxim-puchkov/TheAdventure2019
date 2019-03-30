//
//  Inventory.h
//  Item: Inventory
//  com.maximpuchkov.Faworki.Item.Inventory
//
//  Created by mpuchkov on 2019-01-17. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//


#ifndef Inventory_h
#define Inventory_h

#include "ItemController.h"
#include "Collection.h" // !


namespace items {

using InventorySlot = size_t;


/*!
 @class Inventory
 
 @brief Character's set of items.
 
 Limited capacity storage where each element is an object identifier.
 */
class Inventory /*: public ItemControllerDelegate */ {
public:
    
    /* Constructors */
    
    Inventory();
    
    Inventory(unsigned int maxCapacity);
    
    ~Inventory();
    
    
    
    
    /*  */
    
    /*! */
    
    
    
    
    /* */
    
    /*! Identifiers of all items in the inventory */
    vector<Identifier> all() const noexcept;
    
    /*! Add ID of a new item */
    void add(Identifier id) noexcept;
    
    /*! Remove item with ID */
    void remove(Identifier id) noexcept;
    
    /*! Check if item is in the inventory */
    bool contains(Identifier id) const noexcept;
    
    /*! Current size of the inventory */
    size_t size() const noexcept;
    
    /*! Maximum quantity of items this inventory can store */
    size_t capacity() const noexcept;
    
    
private:
    
    /// IO
    void display() const;
    
    unsigned int max_capacity;
    
    std::vector<Identifier> items;
    
};


} /* namespace items */

#endif /* Inventory_h */
