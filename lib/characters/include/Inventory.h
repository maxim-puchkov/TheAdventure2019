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


class Inventory {
public:
    
    Inventory() {
        

        Item i1("first item");
        Collection c1("first container");
        Item i2("second item in first container");
        c1.add(std::move(i2));

        this->items.insert(&i1);
        this->items.insert(&c1);

        this->display();
    }
    
    ~Inventory() { }
    
    void display() const {
        for (auto item : this->items) {
            std::cout << item->getShortDescription() << std::endl;
        }
    }
    
private:
    
    //Collection items = Collection("description");
    
    unordered_set<Item *> items;
    
};

#endif /* Inventory_h */
