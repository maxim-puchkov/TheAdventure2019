//
//  Collection.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Collection.h"
#include <iostream>

string Collection::getDescription() const {
    std::cout << "COLLECTION DESC\n";

    
    std::ostringstream oss;
    oss << this->description << std::endl;
    for (auto& item : this->items) {
        oss << item.getDescription() << std::endl;
    }
    return oss.str();
}
