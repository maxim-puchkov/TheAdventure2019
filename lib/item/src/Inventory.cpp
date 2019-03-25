//
//  Inventory.cpp
//  adventure2019
//
//  Created by admin on 2019-02-11.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Inventory.h"

inline namespace defaults {
    const unsigned int CAPACITY = 20;
}





/* */

Inventory::Inventory()
: capacity(CAPACITY)
{ }


Inventory::Inventory(unsigned int capacity)
: capacity(capacity)
{ }


Inventory::~Inventory()
{ }





/* */

void Inventory::add(Identifier id) {
    
}


void Inventory::remove(Identifier id) {

}


void Inventory::display() const {

}
