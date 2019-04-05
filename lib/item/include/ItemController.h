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
#include "Authenticator.h"

#include "print.h"


namespace items {

using auth::Authenticator;
using ItemIdentifier = Identifier;

// Debug IC construction counter
static long iccc = 0;




/*!
 @class ItemController
 
 @brief Controlls location and ownership of all items in the game world.
 
 
 */
template<typename Key>
class ItemController {
public:

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
    const ItemBuilder builder = ItemBuilder();
    
    
    /*! Item Controller identifier */
    const Identifier controller_id;
    
    
    
    
    /* Item Controller constructors */
    
    // Using new authenticator
    ItemController()
    : controller_id(0), authenticator(Authenticator<ItemIdentifier>()) {
        this->init();
    }
    
    // Using shared authenticator
    ItemController(const Authenticator<ItemIdentifier> &auth)
    : controller_id(auth.parent_id), authenticator(auth) {
        this->init();
    }
    
    
    /* Create new items in the game world */
    
    
    /*!
     Create a new item in a container
     
     @param key Unique key that identifies the container
     
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Key key) const {
        return this->create(key, 0);
    }
    
    /*!
     Create a new item in a container
     
     @param key Unique key that identifies the container
     @param json_id Specify item's original id read from input JSON files
     
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Key key, unsigned int json_id) const {
        
        if (!this->builder.validate()) {
            return this->controller_id;
        }
    
        //return 1;
        
        
        
        // Cast
        this->created++;
        
       
        // Redundant if
        if (!this->env2d.exists(key)) {
            
            debug::print("1. Allocating container environment for ", key);
            debug::print("2");
            Environment<ItemSearchKey, Item> newContainer;
            debug::print("3");
            auto item = this->buildUniqueItem();
            debug::print("4");

            newContainer.bind(ItemSearchKey(item), item);
            debug::print("5");
            this->env2d.bind(key, newContainer);
            debug::print("6");
            
            return item.id;
            
        } else {
            
            debug::print("1. Looking up existing container environment for ", key);
            Environment<ItemSearchKey, Item> container = this->env2d.lookup(key);
            debug::print("2");
            auto item = this->buildUniqueItem();
            debug::print("3");
            container.bind(ItemSearchKey(item), item);
            debug::print("4");
            this->update(key, container);
            debug::print("5");
            return item.id;
            
        }
    }
    
    /*! @return Total number of items created in the world */
    size_t itemsCreated() const noexcept {
        return this->created;
        //return this->items_created;
    }
    
    
    
    
    // not public
    void update(Key key, Environment<ItemSearchKey, Item> &container) const {
        this->env2d.unbind(key);
        this->env2d.bind(key, container);
    }
    /*! Generate unique id and build a new item */
    Item buildUniqueItem() const noexcept {
        ItemIdentifier id = this->authenticator.generateUniqueIdentifier();
        return this->builder.build(id);
    }
    

    /// Search for all items matching a keyword
    vector<ItemIdentifier> search(Key key, const string &keyword) const {
        vector<Identifier> vec;
        auto env = this->env2d.lookup(key);
        
        for (auto element : env) {
            ItemSearchKey key = element.first;
            if (key.keywords.contains(keyword)) {
                vec.push_back(key.id);
            }
        }
        
        return vec;
    }
    
    
    /*! Key is room.id, itermIdentifier is it's id */
    Item lookup(Key key, ItemIdentifier id) const noexcept(false) {
        return this->env2d.lookup(key).lookup({id, {}});
    }




    /*! */
    Item lookup(Key key, const Keywords &keywords) const noexcept(false) {
        /// return this->env2d.lookup(key)->lookup({0, keywords});
        auto env = this->env2d.lookup(key);
        for (auto element : env) {
            ItemSearchKey key = element.first;
            debug::print("IC3. ", key.id);
            if (key == ItemSearchKey{0, keywords}) {
                return element.second;
            }
        }
        
        throw std::invalid_argument("IC lookup");
    }
    
    
    
    /*! Determine if item exists by its identifier */
    bool exists(Key key, ItemIdentifier id) const noexcept {
        if (this->env2d.exists(key)) {
            auto env = this->env2d.lookup(key);
            for (auto element : env) {
                ItemSearchKey key = element.first;
                if (key == ItemSearchKey{id, {}}) {
                    return true;
                }
            }
        }
        return false;
        
    }
    
    
    
    /*! Check if item matching the keywords exists in a container */
    bool exists(Key key, const Keywords &keywords) const noexcept {
        if (this->env2d.exists(key)) {
            auto env = this->env2d.lookup(key);
            
            for (auto element : env) {
                ItemSearchKey key = element.first;
                if (key == ItemSearchKey{0, keywords}) {
                    return true;
                }
            }
            
        }
        
        return false;
    }
    
    
    /*!
     Contents of a container
     @return Vector of {id, keywords} pairs
     */
    vector<ItemSearchKey> contentsOf(Key key) const {

        //Return an empty vector if env2d. doesn't exist for that char.id or room.id
        if(!env2d.exists(key)){
            return vector<ItemSearchKey>();
        }


        auto env = this->env2d.lookup(key);
        vector<ItemSearchKey> vec;
        vec.reserve(env.size());
        
        for (auto &binding : env) {
            ItemSearchKey key = binding.first;
            //vec.push_bakey(key.id);
            vec.push_back(key);
        }
        
        return vec;
        
    }




    /*! */
    size_t containerSize(Key key) const noexcept {
        if (this->env2d.exists(key)) {
            auto env = this->env2d.lookup(key);
            return env.size();
        }
        
        return 0;
    }
    

    
    
    void reassign(Key key_owner,
                  Key key_recipient,
                  ItemIdentifier id) const noexcept(false) {
        
        auto owner = this->env2d.lookup(key_owner);
        auto recipient = this->env2d.lookup(key_recipient);
        
        
        print_contentsOf(key_owner);
        std::cout << "\n";
        print_contentsOf(key_recipient);
        
        
        Item item = owner.lookup(id);
        
        owner.unbind(id);
        recipient.bind({id, item.keywords}, item);
        
        this->env2d.unbind(key_owner);
        this->env2d.bind(key_owner, owner);
        
        this->env2d.unbind(key_recipient);
        this->env2d.bind(key_recipient, recipient);
        
        std::cout << "\n";
        print_contentsOf(key_owner);
        std::cout << "\n";
        print_contentsOf(key_recipient);
        
    }
        



    
    void print_contentsOf(Key key) const {
        for (auto &x : contentsOf(key)) {
            debug::print("Container id ", key, " owns ", x.toString());
        }
    }

    
  
    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    
    
        
    void display_all() const {
        debug::print(this->env2d);
    }

    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    
    ~ItemController() = default; // { this->deallocateContainers(); }

    
    
private:

    /*! All existing items are stored in the two-dimensional environment */
    mutable Environment<Key, Environment<ItemSearchKey, Item>> env2d;
    
    mutable size_t created = 0;
    
    /*! Local item authenticator */
    const Authenticator<ItemIdentifier> authenticator;
    
    
    
    void init() {
        debug::prefix("ItemController");
        debug::print("ItemController (id: ", this->controller_id, ") created");
        debug::silenced = true;
        iccc++;
    }
    

    // Not called
    void deallocateContainers() const noexcept(false) {
        for (auto &binding : this->env2d) {
            Key key = binding.first;
            Environment<ItemSearchKey, Item>env = binding.second;
            this->env2d.unbind(key);
        }
    }
    
    //
    bool removeItem(Environment<ItemSearchKey, Item> &owner,
                    ItemIdentifier id) const noexcept {
        
        ItemSearchKey key(id);
        if (owner.exists(key)) {
            owner.unbind(key);
            return true;
        }
        
        return false;
        
    }
    
    /*! Keeps trakey of dynamic memory deallocations */
    //mutable ICMemory memory;
    
    //    /// Create an item in the container
    //    ItemIdentifier updateContainer(Key key, Environment<ItemSearchKey, Item> &container) const {
    //        return this->contrller_id;
    //    }

};

    

} /* namespace items */

#endif /* ItemController_h */
