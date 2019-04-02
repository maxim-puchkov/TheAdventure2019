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
#include "ICMemory.h"
#include "print.h"


namespace items {

using auth::Authenticator;
using ItemIdentifier = Identifier;


/// IC
template<typename ContainerKey>
class ItemController {
public:
    
    const ItemBuilder builder = ItemBuilder();
    
    const Identifier id;
    
    
    ItemController()
    : id(0), authenticator(Authenticator<ItemIdentifier>()) {
        this->init();
    }
    
    ItemController(const Authenticator<ItemIdentifier> &auth)
    : id(auth.parent_id), authenticator(auth) {
        this->init();
    }
    
    
    ~ItemController() /* noexcept(false) */ {
        this->deallocateContainers();
//        this->memory.validate();
//        debug::print("Allocated: ", this->memory.allocs);
//        debug::print("Deallocated: ", this->memory.deallocs);
    }

    
    
    ItemIdentifier create(ContainerKey ck) const {
        if (!this->builder.validate()) {
            return this->id;
        }
        

        //this->memory.items_created++;
        this->created++;
        
        if (!this->env2d.exists(ck)) {
            
            debug::print("1. Allocating container environment for ", ck);
            //this->memory.allocs++;
            debug::print("2");
            Environment<ItemSearchKey, Item> newContainer;
            debug::print("3");
            auto item = this->buildUniqueItem();
            debug::print("4");

            newContainer.bind(ItemSearchKey(item), item);
            debug::print("5");
            this->env2d.bind(ck, newContainer);
            debug::print("6");
            
            return item.id;
            
        } else {
            
            debug::print("1. Looking up existing container environment for ", ck);
            Environment<ItemSearchKey, Item> container = this->env2d.lookup(ck);
            debug::print("2");
            auto item = this->buildUniqueItem();
            debug::print("3");
            container.bind(ItemSearchKey(item), item);
            debug::print("4");
            this->update(ck, container);
            debug::print("5");
            return item.id;
            
        }
    }
    
    
    void update(ContainerKey ck, Environment<ItemSearchKey, Item> &container) const {
        this->env2d.unbind(ck);
        this->env2d.bind(ck, container);
    }
    
    /// Create an item in the container
    ItemIdentifier updateContainer(ContainerKey ck, Environment<ItemSearchKey, Item> &container) const {
        return 0;
        
//        if (!this->builder.validate()) {
////            debug::print();
//            return this->id;
//        }
//
//
//        //Environment<ItemSearchKey, Item> *container;
//        Environment<ItemSearchKey, Item> container;
//        if (!this->env2d.exists(ck)) {
//            debug::print("1. Allocating container environment for ", ck);
//            // container = this->memory.allocate(ck);
//            this->allocs++;
//            container = Environment
//            this->env2d.bind(ck, container);
//        } else {
//            debug::print("1. Looking up existing env2d for ", ck);
//            container = this->env2d.lookup(ck);
//        }
        
        
//        ItemIdentifier id = this->authenticator.generateUniqueIdentifier();
//
//        Item item = this->builder.build(id);
//
//        /// @warning bug keywors==
//        container.bind({id, item.keywords}, item);
//
//        return container;
        
//        debug::print("4. Bound in container: ", (*container).toString());

        /// @warning bug
//        this->env2d.modify(ck, container);
//        this->env2d.unbind(ck);
//        this->env2d.bind(ck, container);
        
        
//        debug::print("5. Item env2d updated: ", this->env2d.toString());
        
//        debug::print("6. env2d size: ", this->env2d.size());
        
        
//        this->memory.items_created++;
//        debug::print("7. Items created: ", this->memory.items_created);

        
        return id;
        
    }
    
    
    /*! Generate unique id and build a new item */
    Item buildUniqueItem() const noexcept {
        ItemIdentifier id = this->authenticator.generateUniqueIdentifier();
        return this->builder.build(id);
    }
    

    /// Search for all items matching a keyword
    vector<ItemIdentifier> search(ContainerKey ck, const string &keyword) const {
        vector<Identifier> vec;
        auto env = this->env2d.lookup(ck);
        
        for (auto element : env) {
            ItemSearchKey key = element.first;
            if (key.keywords.contains(keyword)) {
                vec.push_back(key.id);
            }
        }
        
        return vec;
    }
    
    
    /*! */
    Item lookup(ContainerKey ck, ItemIdentifier id) const noexcept(false) {
        return this->env2d.lookup(ck).lookup({id, {}});
    }
    
    /*! */
    Item lookup(ContainerKey ck, const Keywords &keywords) const noexcept(false) {
        /// return this->env2d.lookup(ck)->lookup({0, keywords});
        auto env = this->env2d.lookup(ck);
        for (auto element : env) {
            ItemSearchKey key = element.first;
            debug::print("3. ", key.id);
            if (key == ItemSearchKey{0, keywords}) {
                return element.second;
            }
        }
        
        throw std::invalid_argument("IC lookup");
    }
    
    
    
    /*! Determine if item exists by its identifier */
    bool exists(ContainerKey ck, ItemIdentifier id) const noexcept {
        if (this->env2d.exists(ck)) {
            auto env = this->env2d.lookup(ck);
            for (auto element : env) {
                ItemSearchKey key = element.first;
                if (key == ItemSearchKey{id, {}}) {
                    return true;
                }
            }
        }
        return false;
        
    }
    
    // using debug::print;
    
    /*! Check if item matching the keywords exists in a container */
    bool exists(ContainerKey ck, const Keywords &keywords) const noexcept {
        if (this->env2d.exists(ck)) {
            auto env = this->env2d.lookup(ck);
            for (auto element : env) {
                ItemSearchKey key = element.first;
                if (key == ItemSearchKey{0, keywords}) {
                    return true;
                }
            }
        }
        return false;
            //return ((this->env2d.exists(ck)) && (this->env2d.lookup(ck)->exists(ItemSearchKey{0, keywords})));
    }
    
    
    /*!
     Contents of a container
     @return Vector of {id, keywords} pairs
     */
    vector<ItemSearchKey> contentsOf(ContainerKey ck) const {
        
        auto env = this->env2d.lookup(ck);
        vector<ItemSearchKey> vec;
        vec.reserve(env.size());
        
        for (auto &binding : env) {
            ItemSearchKey key = binding.first;
            //vec.push_back(key.id);
            vec.push_back(key);
        }
        
        return vec;
        
    }
    
    /*! */
    size_t containerSize(ContainerKey ck) const noexcept {
        if (this->env2d.exists(ck)) {
            auto env = this->env2d.lookup(ck);
            return env.size();
        }
        
        return 0;
    }
    
    
    bool removeItem(Environment<ItemSearchKey, Item> &owner, ItemIdentifier id) const noexcept {
        ItemSearchKey key(id);
        if (owner.exists(key)) {
            owner.unbind(key);
            return true;
        }
        
        return false;
    }
    
    
    void reassign(ContainerKey ck_owner, ContainerKey ck_recipient, ItemIdentifier id) {
        
        auto owner = this->env2d.lookup(ck_owner);
        auto recipient = this->env2d.lookup(ck_recipient);
        
        print_contentsOf(ck_owner);
        print_contentsOf(ck_recipient);
        
        
        Item item = owner.lookup(id);
        
        owner.unbind(id);
        recipient.bind({id, item.keywords}, item);
        
        this->env2d.unbind(ck_owner);
        this->env2d.bind(ck_owner, owner);
        
        this->env2d.unbind(ck_recipient);
        this->env2d.bind(ck_recipient, recipient);
        

        print_contentsOf(ck_owner);
        print_contentsOf(ck_recipient);
        
    }

    

    
    /**/
    unsigned int itemsCreated() const noexcept {
        return this->created;
    }
    
    /**/
    unsigned int allocations() const noexcept {
        //return this->memory.allocs;
        return 0;
    }
    
    /**/
    unsigned int deallocations() const noexcept {
        //return this->memory.deallocs;
        return 0;
    }
    
    
  
    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    // debug
    void display_all() {
        debug::print(this->env2d);
    }
    
    void print_contentsOf(ContainerKey ck) {
        for (auto &x : contentsOf(ck)) {
            print("id ", ck, ". ", x.toString());
        }
    }

    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    
    
    
    
    
    // using ContainerEnv = Environment<ItemSearchKey, Item>;
    // using GlobalEnv2d = Environment<ContainerKey, ContainerEnv>;
    // mutable GlobalEnv2d env2d;
    
    /*! All existing items are stored in the two-dimensional environment */
    mutable Environment<ContainerKey, Environment<ItemSearchKey, Item>> env2d;
    
    
private:

    /*! Local item authenticator */
    const Authenticator<ItemIdentifier> authenticator;
    
    mutable size_t created = 0;
    
    void init() {
        debug::prefix("ItemController");
        debug::print("ItemController created");
    }
    
    //template<typename K, typename V>

    
    void deallocateContainers() const noexcept(false) {
//        auto keys = this->env2d.keys();
//        while (!keys.empty()) {
//            this->memory.dealloc(keys.front());
//            keys.pop();
//        }
        for (auto &binding : this->env2d) {
            ContainerKey key = binding.first;
            Environment<ItemSearchKey, Item>env = binding.second;
            
            this->env2d.unbind(key);
            // this->memory.deallocate(env);
        }
    }
    
    /*! Keeps track of dynamic memory deallocations */
    //mutable ICMemory memory;
    
};


} /* namespace items */

#endif /* ItemController_h */
