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


namespace items {

using auth::Authenticator;
using ItemIdentifier = Identifier;
// using ContainerIdentifier = Identifier;


/// IC
template<typename ContainerKey>
class ItemController {
public:
    
    const ItemBuilder builder = ItemBuilder();
    
    
    ItemController()
    : authenticator(Authenticator<ItemIdentifier>()) {
        debug::prefix("ItemController");
        debug::print("ItemController created");
    }
    
    //template<typename T>
    //ItemController(Authenticator<T> &&auth)
    ItemController(const Authenticator<ItemIdentifier> &auth)
    : authenticator(auth) {
        debug::prefix("ItemController");
        debug::print("ItemController created");
    }
    
    
    ~ItemController() /* override */ {
        // dealloc
    }


    
    
    /// Create an item in the container
    ItemIdentifier create(ContainerKey ck) const  /* noexcept override */{
        
        Environment<ItemSearchKey, Item> *container;
        
        if (!this->env2d.exists(ck)) {
            debug::print("Allocating container environment for ", ck);
            container = this->alloc(std::forward<ContainerKey>(ck));
        } else {
            debug::print("Looking up existing env2d for ", ck);
            container = this->env2d.lookup(std::forward<ContainerKey>(ck));
        }
        
        ItemIdentifier id = this->authenticator.generateUniqueidentificator();
        
        Item item = this->builder.build(id);
        
        container->bind({id, item.keywords}, item);
        
        this->count++;
        
        return id;
        
    }
    
    
    /// Items owned by the container */
    vector<Identifier> findOwned(ContainerKey ck) const  /* noexcept override */ {
        Environment<ItemSearchKey, Item> *env = this->env2d.lookup(std::forward<ContainerKey>(ck));
        
        vector<Identifier> vec;
        for (auto element : *env) {
            ItemSearchKey key = element.first;
            vec.push_back(key.id);
        }
        return vec;
    }
    
    /**/
    unsigned int itemsCreated() const noexcept {
        return this->count;
    }
    
    /**/
    unsigned int allocations() const noexcept {
        return this->allocs;
    }
    
    /**/
    unsigned int deallocations() const noexcept {
        return this->deallocs;
    }
    
    
    Item lookup(ContainerKey ck, ItemIdentifier id) const noexcept(false) {
        return this->env2d.lookup(ck)->lookup({id, {}});
    }
    
    Item lookup(ContainerKey ck, Keywords &&keywords) const noexcept(false) {
        return this->env2d.lookup(ck)->lookup({0, std::forward<Keywords>(keywords)});
    }
    
    // Check by id
    bool exists(ContainerKey ck, Identifier id) const noexcept {
        return ((this->env2d.exists(ck)) && (this->env2d.lookup(ck)->exists({id, {}})));
    }
    
    // Check by keywords
    bool exists(ContainerKey ck, Keywords &&keywords) const noexcept {
        return ((this->env2d.exists(ck))
                && (this->env2d.lookup(ck)->exists({0, std::forward<Keywords>(keywords)})));
    }
    
    
    
    // debug
    void display_all() {
        debug::print(this->env2d);
    }
    
    
    
    /* * * Deprecated * * */
    
    [[deprecated]] vector<Identifier> search(const string &keyword) const {
        vector<Identifier> vec;
        for (auto element : this->env) {
            ItemSearchKey key = element.first;
            if (key.keywords.contains(keyword)) {
                vec.push_back(key.id);
            }
        }
        return vec;
    }
  
    [[deprecated]] mutable Environment<ItemSearchKey, Item> env;
    
    /* * * Deprecated * * */
    
    
private:
    
    mutable unsigned int count = 0;
    mutable unsigned int allocs = 0;
    mutable unsigned int deallocs = 0;
    
    mutable Environment<ContainerKey, Environment<ItemSearchKey, Item> *> env2d;
    
    const Authenticator<ItemIdentifier> authenticator;
    
    
    
    //template<typename K, typename V>
    Environment<ItemSearchKey, Item>* alloc(ContainerKey &&ck) const noexcept {
        auto *containerEnv = new Environment<ItemSearchKey, Item>();
        this->env2d.bind(std::forward<ContainerKey>(ck), containerEnv);
        this->allocs++;
        return containerEnv;
    }
    
    
    //template<typename K, typename V>
    void dealloc(ContainerKey &&ck) const noexcept(false) {
        Environment<ItemSearchKey, Item> *containerEnv = this->env2d.lookup(std::forward<ContainerKey>(ck));
        this->env2d.unbind(std::forward<ContainerKey>(ck));
        this->deallocs++;
        delete containerEnv;
    }
    
};


} /* namespace items */

#endif /* ItemController_h */
