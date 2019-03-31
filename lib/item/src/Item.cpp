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
//    debug::prefix("Item");
//    debug::print("Created ", this->toString());
}


Item::~Item() {
//    debug::print("Destroyed ", this->toString());
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
    //const char NL = '\n';
    //const char TAB = '\t';
    //const string DELIM = {NL, TAB};
    const string DELIM = ", ";
    
    stream << "Item (";
    stream << "id: " << this->id << DELIM;
    stream << "keywords: {" << this->keywords.toString() << "}" << DELIM;
    stream << "description: " << this->description.toString() << "" << DELIM;
    stream << "actions: {" << this->actions.toString() << "}";
    stream << ")";
    
    return stream.str();
}


Text Item::examine(const Key &keyword) const {
    
    // .....
    return "callee: Item::examine(const Key&)";
    
}


bool Item::isInteractable() const {
    return !this->actions.empty();
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


bool Item::operator==(Item &other) const {
    return (this->id == other.id);
}

bool Item::operator==(const Item& other) const {
    return (this->id == other.id);
}


} /* namespace items */





namespace std {


size_t hash<Item>::operator()(const Item &item) const {
    return hash<items::Identifier>{}(item.identifier());
}


} /* namespace std */
