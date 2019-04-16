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
#include "auth.hpp"

#include "ICData.h"

#include "print.h"


namespace items {

using namespace auth;
using ItemIdentifier = Identifier;
using Container = _TContainer<ItemSearchKey, Item>;
using Container2d = _TContainer2d<Identifier, Container<ItemSearchKey, Item>>;


/*!
 @class ItemController
 
 @brief Controlls location and ownership of all items in the game world.
 
 @note Idea was to use composite template Key (simiar to ItemSearchKey)
    to allow chaining a container to a container.
 @note Obviously missing the capacities and all containers are infinite.
 @note Security seems pointless as commands could overwrite the world itself
 */
template<typename Key>
class ItemController {
public:
    
    /* Default constructor and destructor */
    
    ItemController() = default;
    ~ItemController() = default;
    

    
    /*! Item Controller's unique identifier */
    const Identifier controller_id = 0;
    
    
    /*! Properties of to-be-created items are set in the builder */
    const ItemBuilder builder;
    
    
    /*!
     - Allocate additional item containers.
     - Create unique objects in existing containers.
     - Check existance, search for matches, or lookup object's symbolic data.
     - Specify identifier of owner's item container.
     */
    const ICData<Key> storage;

    
    
    
    /* Use Item Builder */
    
    /*!
     Create a new item in a container
     @param key Composition of properties that defines each container's
     location, type of contained objects, and structure
     @param json_id Original ID read from an input file (optional)
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Key key) const noexcept;
    ItemIdentifier create(Key key, int json_id = 0) const noexcept;
    
    
    
    
    // Display for debugging
    Text detailsOfList(Key key, const vector<ItemIdentifier> &vec) const;
    Text detailsOfList(const vector<ItemSearchKey> &vec) const noexcept;
    

    
private:

    /*! All existing items are stored in the two-dimensional environment */
    Container2d env2d;
    
    /*! Quantity of items created by this builder */
    std::size_t items_created = 0;
    
    
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
    
    
    /*! Update */
    void update(Key key, Container &container) const {
        (const_cast<ItemController<Key> *>(this))->env2d.unbind(key);
        (const_cast<ItemController<Key> *>(this))->env2d.bind(key, container);
    }
    
    /*! Request unique id and build a new item */
    Item buildUniqueItem() const noexcept {
        ItemIdentifier id = auth::shared::authenticator.requestUniqueIdentifier();
        return this->builder.build(id);
    }

};


} /* namespace items */


#include "ItemController.cpp"

#endif /* ItemController_h */
