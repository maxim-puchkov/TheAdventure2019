//
//  Collection.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Collection.h"

// using namespace objects;
//using items::Collection;

namespace items {


/* Constructors */

//Collection::Collection()
//{ }


Collection::~Collection()
{ }


Collection::Collection(const Item &container, unsigned int capacity)
: container(container), capacity(capacity) {
//    for (unsigned int i = 0; i < capacity; i++) {
//        // this->set.insert(Slot(i));
//    }
}






/* Object interface */

Identifier Collection::identifier() const {
    return this->collectionID;
}


Key Collection::brief() const {
    return this->keywords.first();
}


Text Collection::toString() const {
    ostringstream stream{""};
    const char NL = '\n';
    const char TAB = '\t';
    
    stream << this->keywords.first();
    stream << NL;
    for (auto &itemID : this->set) {
        stream << TAB << itemID << NL;
    }
    
    stream << "Total size: " << this->size();
    
    return stream.str();
    
}


Text Collection::examine(const Key &keyword) const {
    
    // .....
    return "callee: Collection::examine(const Key&)";
    
}






/* Set operations */

bool Collection::insert(const Item &item) {
    return this->set.insert(item.identifier()).second;
}

bool Collection::insert(Identifier id) {
    return this->set.insert(id).second;
}


bool Collection::erase(const Item &item) {
    bool valid = (this->set.find(item.identifier()) != this->set.cend());
    this->set.erase(item.identifier());
    return valid;
}

bool Collection::erase(Identifier id) {
    bool valid = (this->set.find(id) != this->set.cend());
    this->set.erase(id);
    return valid;
}


bool Collection::contains(Identifier id) const {
    return (this->set.find(id) != this->set.cend());
}


size_t Collection::size() const {
    return this->set.size();
}


std::set<Identifier>::const_iterator Collection::begin() const {
    return this->set.cbegin();
}


std::set<Identifier>::const_iterator Collection::end() const {
    return this->set.cend();
}


} /* namespace items */
