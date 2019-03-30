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

#include "Item.h"
#include "ItemBuilder.h"
#include "Authenticator.h"


namespace items {

using auth::Authenticator;

// IC
class ItemController {
public:
    
    
    const ItemBuilder builder;
    
    
    ItemController()
    : builder(ItemBuilder())
    { }
    
    Item lookup(Identifier id) {
        return Item(0, {}, {}, {{}});
    }
    
    Item create() {
        // Generate unique id and create item
        Identifier id = this->authenticator.generateUniqueIdentifier();
        Item item = this->builder.build(id);
        
        // 
        this->env.bind(id, item);
        return item;
    }
    
    
    
    
    
protected:
    
    
    bool exists(Identifier id) {
        return this->env.exists(id);
    }
    
    

    
    
    Environment<Identifier, Item> env;
    
    
private:
    
    
    Authenticator<Identifier> authenticator;
    
    
};


} /* namespace items */

#endif /* ItemController_h */
