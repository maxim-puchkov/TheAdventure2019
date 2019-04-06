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

#include "print.h"


namespace items {

using namespace auth;
using ItemIdentifier = Identifier;


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
    
    using Container = Environment<ItemSearchKey, Item>;
    using Container2d = Environment<Key, Container>;
    // using Container3d = Environment<Key, Container2d>
    // using Container4d = ...

    
    /*!
     @brief
        Properties of to-be-created items are set in the builder
     
     @discussion
         Before creating a new item, specify its keywords (required)
            builder.setKeywords( {"keyword1", "keyword 2"} )
     
         Optionally, other properties may be specified
            .setDescription(string)
            .setActions( { {string, string}, {string, string}, ...} )
     
     @note
        Upcoming for equipable items:
            .setAttributes( )
     */
    const ItemBuilder builder;
    
    
    
    
    /*!
     Create a new item in a container
     
     @param key Unique key that identifies the container
     
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Key key) const noexcept {
        return this->create(key, -1);
    }
    
    
    /*!
     Create a new item in a container
     
     @param key Unique key that identifies the container
     @param json_id Specify item's original id read from input JSON files
     
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Key key, int json_id) const noexcept;
    
    
    
    
    
    

    /*! Search for all items matching a keyword in a container */
    vector<ItemIdentifier> search(Key key, const string &keyword) const noexcept;
    
    
    /*! Lookup item object by its identifier */
    Item lookup(Key key, ItemIdentifier id) const noexcept(false);
    
    /*! Lookup item object by its keywords */
    Item lookup(Key key, const Keywords &keywords) const noexcept(false);
    
    
    /*! Check if item exists in a container by its identifier */
    bool exists(Key key, ItemIdentifier id) const noexcept;
    
    /*! Check if item matching the keywords exists in a container */
    bool exists(Key key, const Keywords &keywords) const noexcept;
    
    
    
    
    /*!
     Contents of a container
     @return Vector of {id, keywords} pairs
     */
    vector<ItemSearchKey> contentsOf(Key key) const;
    
    /*! Change ownership */
    void reassign(Key key_owner,
                  Key key_recipient,
                  ItemIdentifier id) const;
    
    
    /*! Quantity of items in a container */
    std::size_t containerSize(Key key) const noexcept;
    
    /*! @return Total number of items created in the world */
    std::size_t itemsCreated() const noexcept;
    
        
        
        
        



    
  
    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    
    void display_all() const {
        debug::print(this->env2d);
    }
    
    void print_contentsOf(Key key) const {
        for (auto &x : contentsOf(key)) {
            debug::print("Container id ", key, " owns ", x.toString());
        }
    }

    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    

    
    /*! Item Controller identifier */
    const Identifier controller_id = 0;
    
    
//    // Using shared authenticator
//    ItemController(SharedAuthenticator authenticator)
//    : authenticator(authenticator) { //, controller_id(authenticator->parent_id) {
//        this->init();
//    }
    
    
    ItemController()
    { }
    
    
    ~ItemController() = default; // { this->deallocateContainers(); }
    
    
    Text detailsOfList(Key key, const vector<ItemIdentifier> &vec) const {
        std::ostringstream stream("");
        
        stream << "Listing items:\n";
        for (auto &id : vec) {
            stream << '\t' << this->env2d.lookup(key).lookup(id).toString() << '\n';
        }
        
        return stream.str();
    }
    
    
    //Text detailsOfList(vector<ItemSearchKey> &&vec) const noexcept {
    Text detailsOfList(const vector<ItemSearchKey> &vec) const noexcept {
        std::ostringstream stream("");
        
        stream << "Listing items:\n";
        for (auto &skey : vec) {
            stream << '\t' << skey.toString() << '\n';
        }
        
        return stream.str();
    }
    
    
    /*! Remove an item from its owner */
    bool removeItem(Environment<ItemSearchKey, Item> &owner,
                    ItemIdentifier id) const noexcept {
        
        ItemSearchKey key(id);
        if (owner.exists(key)) {
            owner.unbind(key);
            return true;
        }
        
        return false;
    }
    
    
private:

    /*! All existing items are stored in the two-dimensional environment */
    Environment<Key, Environment<ItemSearchKey, Item>> env2d;
    
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
            Environment<ItemSearchKey, Item> env = binding.second;
            // this->env2d.unbind(key);  cast
        }
    }
    
    
    /*! Update */
    void update(Key key, Environment<ItemSearchKey, Item> &container) const {
        (const_cast<ItemController *>(this))->env2d.unbind(key);
        (const_cast<ItemController *>(this))->env2d.bind(key, container);
    }
    
    /*! Request unique id and build a new item */
    Item buildUniqueItem() const noexcept {
        ItemIdentifier id = auth::shared::authenticator.requestUniqueIdentifier();
        return this->builder.build(id);
    }
    
    /*! Keeps trakey of dynamic memory deallocations */
    //mutable ICMemory memory;
    
    //    /// Create an item in the container
    //    ItemIdentifier updateContainer(Key key, Environment<ItemSearchKey, Item> &container) const {
    //        return this->contrller_id;
    //    }

};

    

} /* namespace items */


#include "ItemController.cpp"

#endif /* ItemController_h */
