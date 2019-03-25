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
    
    Inventory();
    
    ~Inventory();
    
    void add(Identifier id);
    
    void remove(Identifier id);
    
    bool contains(Identifier id); /* undefined */
    
    void display() const;
    
private:
    
    //Collection items = Collection("description");
    
    //unordered_set<void *> items;
    
    Collection items;
    
};

#endif /* Inventory_h */
