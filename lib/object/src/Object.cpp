//
//  Object.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Object.h"


objects::Object::Object() {
    debug::PrefixMessage = "\tObject:";
    debug::print("Object created.");
}

objects::Object::~Object() {
    debug::print("Object destroyed.");
}

