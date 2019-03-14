//
//  ItemConstructor.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemConstructor.h"

ItemConstructor::ItemConstructor()
{ }


Item ItemConstructor::create() {
    ObjectId id = uniqueId();
    return Item(id, keywords, description, extras);
}
