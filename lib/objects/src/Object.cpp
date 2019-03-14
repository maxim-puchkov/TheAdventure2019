//
//  Object.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Object.h"

namespace objects {
    
static unsigned int lastId = 0;

unsigned long Object::uniqueId() {
    return ++lastId;
}

}
