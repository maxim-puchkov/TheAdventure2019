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

const string DESCRIPTION = "Your Inventory";

class Inventory {
public:
    
    Inventory() {
        Item i1("first item");
        Collection c1("first container");
        Item i2("in container 1");
        c1.add(std::move(i2));
        
        items.add(std::move(i1));
        items.add(std::move(c1));
        
        this->listItems();
    }
    
    ~Inventory() { }
    
    void listItems() const {
        for (auto& item : this->items.getItems()) {
            std::cout << item.getDescription() << std::endl;
        }
    }
    
private:
    
    Collection items = Collection(DESCRIPTION);
    
};

#endif /* Inventory_h */
