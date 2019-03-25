//
//  Collection.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Collection.h"
using namespace objects;





/* Constructors */

Collection::Collection()
{ }


Collection::~Collection()
{ }


Collection::Collection(const Item &item, unsigned int capacity)
: container(item), capacity(capacity) {
    for (unsigned int i = 0; i < capacity; i++) {
        // this->set.insert(Slot(i));
    }
}






/* Object interface */

Identifier Collection::id() const {
    return this->collectionID;
}


Key Collection::brief() const {
    return this->keywords.first();
}


Text Collection::display() const {
    return this->keywords.asString();
}


Text Collection::examine(const Key &keyword) const {
    
    // .....
    return "callee: Collection::examine(const Key&)";
    
}






/* Set operations */

bool Collection::insert(const Item &item) {
    return this->set.insert(item.id()).second;
}


bool Collection::erase(const Item &item) {
    bool valid = (this->set.find(item.id()) != this->set.cend());
    this->set.erase(item.id());
    return valid;
}


size_t Collection::size() {
    return this->set.size();
}
