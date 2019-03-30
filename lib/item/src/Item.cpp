//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"
#include "ItemHash.h"


namespace items {


/* Constructors */

Item::Item(Identifier id,
           const Keywords &keywords,
           const Description &description,
           const Actions &actions)
: id(id), keywords(keywords), description(description), actions(actions)
{
    debug::prefix("Item");
    debug::print("Created item (keywords: {", keywords.toString(), "}, actions: {", actions.toString(), "})");
}


Item::~Item() {
    debug::print("Item destroyed (id: ", id,
                 ", keywords: {", keywords.toString(), "})");
}






/* Object Interface */

Identifier Item::identifier() const {
    return this->id;
}


Key Item::brief() const {
    return this->keywords.toString();
}


Text Item::toString() const {
    return this->description.full();
}


Text Item::examine(const Key &keyword) const {
    
    // .....
    return "callee: Item::examine(const Key&)";
    
}






/* Operators */

Item& Item::operator=(Item &other) {
    //this->itemID = other.identifier();
    this->keywords = other.keywords;
    this->description = other.description;
    this->actions = other.actions;
    return *this;
}


Item& Item::operator=(const Item &other) {
    //this->itemID = other.identifier();
    this->keywords = other.keywords;
    this->description = other.description;
    this->actions = other.actions;
    return *this;
}

} /* namespace items */





namespace std {


size_t hash<Item>::operator()(const Item &item) const {
    return hash<unsigned long>{}(item.identifier());
}


} /* namespace std */
