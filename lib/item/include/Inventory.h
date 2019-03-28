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


namespace items {


/*!
 @class Inventory
 
 @brief Character's set of items.
 
 Limited capacity storage where each element is an object identifier.
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
    
private:
    
    void display() const;
    
    //Collection items = Collection("description");
    
    //unordered_set<void *> items;
    
    unsigned int capacity;
    
    Collection items;
    
};


} /* namespace items */

#endif /* Inventory_h */
