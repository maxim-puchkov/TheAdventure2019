//
//  Inventory.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h

#include "Collection.h"

using objects::Identifier;
using objects::Item;
using objects::Collection;


/**
 *  @class Inventory
 *
 *  @brief Character's set of items.
 */
class Inventory {
public:
    
    /* Constructors */
    
    Inventory();
    
    Inventory(unsigned int capacity);
    
    ~Inventory();
    
    
    
    
    
    /* */
    
    void add(Identifier id);
    
    void remove(Identifier id);
    
    bool contains(Identifier id) const;
    
    size_t size() const;
    
    void display() const;
    
private:
    
    //Collection items = Collection("description");
    
    //unordered_set<void *> items;
    
    unsigned int capacity;
    
    Collection items;
    
};

#endif /* Inventory_h */
