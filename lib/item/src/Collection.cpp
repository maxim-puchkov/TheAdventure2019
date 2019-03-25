//
//  Collection.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Collection.h"
using namespace objects;



Identifier Collection::id() const {
    return this->collectionID;
}


Key Collection::brief() const {
    return this->keywords.first();
}


Text Collection::display() const {
    return this->keywords.asString();
}


bool Collection::hasKeyword(const Key &keyword) const {
    return this->keywords.contains(keyword);
}


Text Collection::examine(const Key &keyword) const {
    
    // .....
    return "callee: Collection::examine(const Key&)";
    
}
