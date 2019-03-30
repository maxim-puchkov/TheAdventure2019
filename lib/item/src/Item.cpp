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


Text Item::brief() const {
    return this->keywords.toString();
}


Text Item::toString() const {
    ostringstream stream{""};
    const char NL = '\n';
    const char TAB = '\t';
    const string DELIM = {NL, TAB};
    
    stream << "Item (" << DELIM;
    stream << "id: " << this->id << "," << DELIM;
    stream << "keywords: {" << this->keywords.toString() << "}," << DELIM;
    stream << "description: " << this->description.toString() << "," << DELIM;
    stream << "actions: {" << this->actions.toString() << "}," << NL;
    stream << ")";
    
    return stream.str();
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
    return hash<items::Identifier>{}(item.identifier());
}


} /* namespace std */
