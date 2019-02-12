//
//  Collection.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Collection.h"

string Collection::getShortDescription() const {
    std::ostringstream oss;
    oss << "Bag: " << this->shortDescription << std::endl;
    if (this->items.empty()) {
        oss << "<empty>" << std::endl;
        return oss.str();
    }
    
    for (auto& item : this->items) {
        oss << item.getShortDescription() << std::endl;
    }
    return oss.str();
}

string Collection::getLongDescription() const {
    return "long desc";
}
