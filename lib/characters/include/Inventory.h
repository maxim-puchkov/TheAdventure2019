//
//  Inventory.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h

#include <iostream>
#include <string>
#include <unordered_set>
#include "Item.h"
#include "Collection.h"


using std::unordered_set;
using std::string;

/**
 *  @class Inventory
 *
 *  @brief Character's set of items.
 */
class Inventory {
public:
    
    Inventory();
    
    ~Inventory();
    
    void add(Item *item);
    
    Item remove(Item *item);
    
    void display() const;
    
private:
    
    //Collection items = Collection("description");
    
    unordered_set<Item *> items;
    
};

#endif /* Inventory_h */
