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
    @n
    @class  ItemController
    @brief  Controlls location and ownership of all items in the game world
 */
template<typename Inventory>
class ItemController {
public:

    /*!
     @property  builder
     @brief     Sets properties of items that will be created
  
     Before creating a new item, specify its keywords (required)
     @code
        builder.setKeywords( {"keyword1", "key word 2"} )
        builder.setKeywords( {"keyword1", "key word 2"} )
     @endcode
     
     Optionally, other properties may be specified
     @code
        .setDescription(string)
        .setActions( {{action_1, description_a1},
            {action_2, description_a2},
            {...}} )
     @endcode
     
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
        debug::print(" INIT with new ");
    }
    
    // Using shared authenticator
    ItemController(const Authenticator<ItemIdentifier> &auth)
    : controller_id(auth.parent_id), authenticator(auth) {
        this->init();
        debug::print(" INIT with other ");
    }
    
    
    /* Create new items in the game world */
    
    
    /*!
     Create a new item in a container
     @param inv_id Unique key that identifies the container
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Inventory inv_id) const {
        return this->create(inv_id, 0);
    }
    
    /*!
     Create a new item in a container
     @param inv_id Unique key that identifies the container
     @param json_id Specify item's original id read from input JSON files
     @return Unique identifier of the new item
     */
    ItemIdentifier create(Inventory inv_id, unsigned int json_id) const {
        if (!this->builder.validate()) {
            return this->controller_id;
        }
        
        this->created++;
        if (!this->env2d.exists(inv_id)) {
//            debug::print("1. Allocating container environment for ", key);
            Environment<ItemSearchKey, Item> newContainer;
            auto item = this->buildUniqueItem();
            newContainer.bind(ItemSearchKey(item), item);
            this->env2d.bind(inv_id, newContainer);
            return item.id;
        } else {
//            debug::print("1. Looking up existing container environment for ", key);
            Environment<ItemSearchKey, Item> container = this->env2d.lookup(inv_id);
            auto item = this->buildUniqueItem();
            container.bind(ItemSearchKey(item), item);
            this->update(inv_id, container);
            return item.id;
        }
    }
    
    /*! @return Total number of items created in the world */
    std::size_t itemsCreated() const noexcept {
        return this->created;
    }
    
    
    
    
    // not public
    
    
    void update(Inventory inv_id, Environment<ItemSearchKey, Item> &container) const {
        this->env2d.unbind(inv_id);
        this->env2d.bind(inv_id, container);
    }
    /*! Generate unique id and build a new item */
    Item buildUniqueItem() const noexcept {
        ItemIdentifier id = this->authenticator.generateUniqueIdentifier();
        return this->builder.build(id);
    }
    

    /// Search for all items matching a keyword
    std::vector<ItemIdentifier> search(Inventory inv_id, const string &keyword) const {
        std::vector<ItemIdentifier> vec;

        // Return an empty vector if Inventory for that character.id or room.id doesn't exist
        if (!env2d.exists(inv_id)) {
            return vector<ItemIdentifier>{};
        }
        auto env = this->env2d.lookup(inv_id);
        for (auto &element : env) {
            ItemSearchKey key = element.first;
            if (key.keywords.contains(keyword)) {
                vec.push_back(key.id);
            }
        }
        return vec;
    }
    
    
    /// Lookup item ID in the container of items with ID=`key`
    Item lookup(Inventory inv_id, ItemIdentifier id) const noexcept(false) {
        return this->env2d.lookup(inv_id).lookup({id, {}});
    }


    /*! */
    Item lookup(Inventory inv_id, const Keywords &keywords) const noexcept(false) {
        /// return this->env2d.lookup(key)->lookup({0, keywords});
        auto env = this->env2d.lookup(inv_id);
        for (auto &element : env) {
            ItemSearchKey key = element.first;
            debug::print("IC3. ", key.id);
            if (key == ItemSearchKey{0, keywords}) {
                return element.second;
            }
        }
        throw std::invalid_argument("IC lookup");
    }
    
    
    /*! Determine if item exists by its identifier */
    bool exists(Inventory inv_id, ItemIdentifier id) const noexcept {
        if (this->env2d.exists(inv_id)) {
            auto env = this->env2d.lookup(inv_id);
            for (auto &element : env) {
                ItemSearchKey key = element.first;
                if (key == ItemSearchKey{id, {}}) {
                    return true;
                }
            }
        }
        return false;
    }
    
    
    
    /*! Check if item matching the keywords exists in a container */
    bool exists(Inventory inv_id, const Keywords &keywords) const noexcept {
        if (this->env2d.exists(inv_id)) {
            auto env = this->env2d.lookup(inv_id);
            for (auto &element : env) {
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
    vector<ItemSearchKey> contentsOf(Inventory inv_id) const {
        //Return an empty vector if env2d. doesn't exist for that char.id or room.id
        if (!env2d.exists(inv_id)) {
            return vector<ItemSearchKey>{};
        }
        auto env = this->env2d.lookup(inv_id);
        vector<ItemSearchKey> vec;
        vec.reserve(env.size());
        for (auto &binding : env) {
            ItemSearchKey key = binding.first;
            vec.push_back(key);
        }
        return vec;
    }




    /*! */
    std::size_t containerSize(Inventory inv_id) const noexcept {
        if (this->env2d.exists(inv_id)) {
            auto env = this->env2d.lookup(inv_id);
            return env.size();
        }
        return 0;
    }
    

    
    
    void reassign(Inventory sender_id,
                  Inventory recipient_id,
                  ItemIdentifier id) const noexcept(false) {
        auto sender = this->env2d.lookup(sender_id);
        auto recipient = this->env2d.lookup(recipient_id);
        
        std::cout << '\n';
        print_contentsOf(sender_id);
        std::cout << '\n';
        print_contentsOf(recipient_id);
        
        Item item = sender.lookup(id);
        sender.unbind(id);
        recipient.bind({id, item.keywords}, item);
        
        this->env2d.unbind(sender_id);
        this->env2d.bind(sender_id, sender);
        
        this->env2d.unbind(recipient_id);
        this->env2d.bind(recipient_id, recipient);
        
        std::cout << '\n';
        print_contentsOf(sender_id);
        std::cout << '\n';
        print_contentsOf(recipient_id);
    }
    
    
    void print_contentsOf(Inventory inv_id) const {
        for (auto &item : contentsOf(inv_id)) {
            debug::print("Container id ", inv_id, " owns ", item.toString());
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
    mutable Environment<Inventory, Environment<ItemSearchKey, Item>> env2d;
    
    mutable std::size_t created = 0;
    
    /*! Local item authenticator */
    const Authenticator<ItemIdentifier> authenticator;
    
    
    
    void init() {
        debug::prefix("ItemController");
        iccc++;
        debug::print("ItemController (id: ", this->controller_id, ") created (IC-C count = ", iccc, ")");
//        debug::silenced = true;
    }
    

    // Not called
    void deallocateContainers() const noexcept(false) {
        for (auto &binding : this->env2d) {
            Inventory inv_id = binding.first;
            Environment<ItemSearchKey, Item> env = binding.second;
            this->env2d.unbind(inv_id);
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
    //    ItemIdentifier updateContainer(Inventory inv_id, Environment<ItemSearchKey, Item> &container) const {
    //        return this->contrller_id;
    //    }

};

    

} /* namespace items */

#endif /* ItemController_h */
