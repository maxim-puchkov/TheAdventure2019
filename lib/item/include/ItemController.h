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
#include "ItemSearchKey.h"
#include "ItemBuilder.h"
#include "ICData.h"

#include "auth.hpp"
#include "print.h" // debug

namespace items {
    
using namespace auth;


/*!
 @class ItemController
 
 @brief Controlls location and ownership of all items in the game world
 
 Items may be created in a container. Characters' and Rooms' identifiers are used as template parameter Key to specify containers.
 */
template<typename Key>
class ItemController {
public:
    
    ItemController() = default;
    
    
    using Container = Environment<ItemSearchKey, Item>;
    using Container2d = Environment<Key, Container>;
    

    
    /*! Item Controller's unique identifier */
    const Identifier controller_id = 0;
    
    
    /*! Properties of to-be-created items are set in the builder */
    const ItemBuilder builder{};
    
    
    /*!
     - Allocate additional item containers.
     - Create unique objects in existing containers.
     - Check existance, search for matches, or lookup object's symbolic data.
     - Specify identifier of owner's item container.
     */
    const ICContainers<Key> storage{};
    
//    constexpr auto contentsOf(Key key) {
//        return storage.contentsOf(key);
//    }
//    constexpr auto lookup(Key key, ItemIdentifier id) {
//        return storage.lookup(key, id);
//    }
//    constexpr auto exists(Key key, ItemIdentifier id) {
//        return storage.exists(key, id);
//    }
//    constexpr auto search(Key key, const Keyword &keyword) {
//        return storage.search(key, keyword);
//    }
    

    
    /*!
     @function create
     
     Create a new item, assign it unique identifier, and place it
     in its owner's container.
     
     @param key Composition of properties that defines each container's
     location, type of contained objects, and structure
     @param json_id Original ID read from an input file (optional)
     @return Unique identifier of the new item
     */
    // ItemIdentifier create(Key key) const noexcept;
    ItemIdentifier create(Key key, int json_id = 0) const noexcept;

    
private:

    /*! All existing items are stored in the two-dimensional environment */
    // Container2d env2d;
    
    /*! Quantity of items created by this builder */
    size_type items_created = 0;
    
    

    
    
    /*! Request unique id and build a new item */
    Item buildUniqueItem() const noexcept {
        // ItemIdentifier id = auth::shared::authenticator.requestUniqueIdentifier();
        auto id = auth::shared::new_uuid();
        return this->builder.build(id);
    }
    
    
    // Not called
    void init() {
        debug::prefix("ItemController");
        debug::print("ItemController (id: ", this->controller_id, ") created");
        debug::silenced = true;
    }
    
    
    // Not called
    void deallocateContainers() const noexcept(false) {
        for (auto &binding : this->env2d) {
            Key key = binding.first;
            Container env = binding.second;
            // this->env2d.unbind(key);  cast
        }
    }
    
    
//    /*! Update */
//    void update(Key key, Container &container) const {
//        (const_cast<ItemController<Key> *>(this))->env2d.unbind(key);
//        (const_cast<ItemController<Key> *>(this))->env2d.bind(key, container);
//    }

};


} /* namespace items */

#include "ItemController.cpp"

#endif /* ItemController_h */
