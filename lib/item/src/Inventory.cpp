//
//  Inventory.cpp
//  Item: Inventory
//  com.maximpuchkov.Faworki.Item.Inventory
//
//  Created by mpuchkov on 2019-02-11. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//


#include "Inventory.h"


namespace items {

inline namespace inventory_defaults {
    //const Identifier EMPTY = 0;
    const unsigned int MAX_CAPACITY = 20;
}


/* Constructors */

Inventory::Inventory()
: Inventory(MAX_CAPACITY)
{ }


Inventory::Inventory(unsigned int max_capacity)
: max_capacity(max_capacity)
{
    debug::prefix("Inventory");
    this->items.reserve(max_capacity);
//    for (auto &slot : this->items) {
//        slot = EMPTY;
//    }
}


Inventory::~Inventory()
{ }





/* ItemControllerDelegate */





/*  */

vector<Identifier> Inventory::all() const noexcept {
    return this->items;
}


void Inventory::add(Identifier id) noexcept {
    debug::print("Adding item's id ", id);
    //debug::print(lookup(id).toString());
    this->items.push_back(id);
}


void Inventory::remove(Identifier id) noexcept {
    //this->items.erase(id);
}


bool Inventory::contains(Identifier id) const noexcept {
    //return this->items.contains(id);
    return false;
}


size_t Inventory::size() const noexcept {
    return this->items.size();
}


void Inventory::display() const {
    debug::PrefixMessage = "Inventory";
    for (const auto &itemID : this->items) {
        debug::print("Item (id: ", itemID, ")");
    }
}


} /* namespace items */
