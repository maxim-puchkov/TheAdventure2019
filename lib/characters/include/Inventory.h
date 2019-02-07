//
//  Inventory.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h

#include <unordered_set>
#include "Item.h"
#include "Collection.h"

using std::unordered_set;
using std::string;


class Inventory {
public:
    
    Inventory() {
        
    }
    
    ~Inventory() { }
    
private:
    
    unordered_set<Item> items;
    
};

#endif /* Inventory_h */
