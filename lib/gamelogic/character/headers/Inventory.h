//
//  Inventory.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h

#include "InteractiveObject.h"
#include "Item.h"

class Inventory : public InteractiveObject {
public:
    
    bool isWearable() { return false; }
    
private:
    
    int capacity;
    
    int currentSize;
    
    Item *items;
    
};

#endif /* Inventory_h */
