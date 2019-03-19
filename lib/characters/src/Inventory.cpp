//
//  Inventory.cpp
//  adventure2019
//
//  Created by admin on 2019-02-11.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Inventory.h"


Inventory::Inventory() {
    
    // Tests:
    
    /*
    Item item1("item 1");
    Collection col1("collection 1");
    Item item2("item 2 in collection 1");
    
    this->add(&item1);
    col1.add(std::move(item2)); 
    this->add(&col1);
    
    this->display();
    */
}


Inventory::~Inventory()
{ }


void Inventory::add(void *item) {
    this->items.insert(item);
}


void Inventory::remove(void *item) {
//    if (this->items.erase(item) == 1) {
//        return *item;
//    }
//    throw std::invalid_argument("Item is not in the inventory");
}


void Inventory::display() const {
//    for (auto item : this->items) {
//        std::cout << "<id " << item->getId() << "> ";
//        std::cout << item->getShortDescription() << std::endl;
//    }
}
