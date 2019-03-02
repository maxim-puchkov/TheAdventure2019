//
//  Identifiers.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Identifiers.h"

static unsigned long uniqueId = 0;

unsigned long Identifiers::uid() {
    return ++uniqueId;
}
