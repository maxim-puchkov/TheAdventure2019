//
//  ItemController.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ItemController
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ItemController_h
#define ItemController_h

#include "Builder.h"
#include "Item.h"
#include "ItemBuilder.h"


namespace items {


class ItemController {
public:
    
    const ItemBuilder builder;
    
    
    ItemController()
    : builder(ItemBuilder())
    { }
    
    Item lookup(Identifier id) {
        return Item();
    }
    
    Item create() {
        return this->builder.build();
    }
    
private:
    
    Environment<Identifier, Item *> env;
    
};


} /* namespace items */

#endif /* ItemController_h */
