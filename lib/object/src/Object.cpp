//
//  Object.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Object.h"


namespace objects {


Object::Object() {
    debug::prefix("Object");
    debug::print("Object created.");
}

Object::~Object() {
    debug::print("Object destroyed.");
}


} /* namespace objects */
