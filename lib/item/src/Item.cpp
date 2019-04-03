//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"


namespace items {


/* Constructors */

Item::Item(ItemIdentifier id,
           const Keywords &keywords,
           const Description &description,
           const Actions &actions)
: id(id), keywords(keywords), description(description), actions(actions)
{ }


    


/* Object Interface */

ItemIdentifier Item::identifier() const {
    return this->id;
}


Text Item::brief() const {
    return this->keywords.toString();
}


Text Item::toString() const {
    ostringstream stream{""};
    const string DELIM = ", ";
    
    stream << "Item (";
    stream << "id: " << this->id << DELIM;
    stream << "keywords: {" << this->keywords.toString() << "}" << DELIM;
    stream << "description: " << this->description.toString() << "" << DELIM;
    stream << "actions: {" << this->actions.toString() << "}";
    stream << ")";
    
    return stream.str();
}


Text Item::examine(const Text &keyword) const {
    
    // .....
    return "callee: Item::examine(const Key&)";
    
}


bool Item::isInteractable() const {
    return !this->actions.empty();
}



/* Operators */

Item& Item::operator=(Item &other) {
    this->keywords = other.keywords;
    this->description = other.description;
    this->actions = other.actions;
    return *this;
}

Item& Item::operator=(const Item &other) {
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


bool Item::operator!=(Item &other) const {
    return (this->id != other.id);
}

bool Item::operator!=(const Item& other) const {
    return (this->id != other.id);
}


} /* namespace items */





namespace std {


size_t hash<Item>::operator()(const Item &item) const {
    return hash<items::ItemIdentifier>{}(item.identifier());
}


} /* namespace std */
