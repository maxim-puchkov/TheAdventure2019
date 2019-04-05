//
//  ItemController.cpp
//  Objects: Builder
//  com.maximpuchkov.Objects.Objects.ItemController
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//



#ifndef ItemController_cpp
#define ItemController_cpp

#include "ItemController.h"


namespace items {


template<typename Key>
ItemIdentifier ItemController<Key>::create(Key key, int json_id) const noexcept {
    
    // Validate building options
    if (!this->builder.validate()) {
        return this->controller_id;
    }
    
    
    // Create a new container if it does not exist
    if (!this->env2d.exists(key)) {
        Environment<ItemSearchKey, Item> emptyContainer;
        (const_cast<ItemController *>(this))->env2d.bind(key, emptyContainer);
    }
    
    
    // Lookup container by its search key
    Environment<ItemSearchKey, Item> container = this->env2d.lookup(key);
    
    
    // Build an item with unique identifier and put it in the container
    Item item = this->buildUniqueItem();
    container.bind(ItemSearchKey(item), item);
    
    
    // Update all items and number of created items
    this->update(key, container);
    (const_cast<ItemController *>(this))->items_created++;
    
    
    return item.id;
    
}


template<typename Key>
vector<ItemIdentifier> ItemController<Key>::search(Key key,
                                                   const string &keyword) const {
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





template<typename Key>
Item ItemController<Key>::lookup(Key key,
                                 ItemIdentifier id) const noexcept(false) {
    return this->env2d.lookup(key).lookup({id, {}});
}


template<typename Key>
Item ItemController<Key>::lookup(Key key,
                                 const Keywords &keywords) const noexcept(false) {
    auto env = this->env2d.lookup(key);
    for (auto element : env) {
        ItemSearchKey key = element.first;
        if (key == ItemSearchKey{0, keywords}) {
            return element.second;
        }
    }
    
    throw std::invalid_argument("IC lookup");
}





template<typename Key>
bool ItemController<Key>::exists(Key key,
                                 ItemIdentifier id) const noexcept {
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


template<typename Key>
bool ItemController<Key>::exists(Key key,
                                 const Keywords &keywords) const noexcept {
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






template<typename Key>
vector<ItemSearchKey> ItemController<Key>::contentsOf(Key key) const {
    auto env = this->env2d.lookup(key);
    vector<ItemSearchKey> vec;
    vec.reserve(env.size());
    
    for (auto &binding : env) {
        ItemSearchKey key = binding.first;
        vec.push_back(key);
    }
    
    return vec;
}


template<typename Key>
void ItemController<Key>::reassign(Key key_owner,
                                   Key key_recipient,
                                   ItemIdentifier id) const {
    
    // Find containers of owner and recipient
    auto owner = this->env2d.lookup(key_owner);
    auto recipient = this->env2d.lookup(key_recipient);
    
    // Find the item and change its owner
    Item item = owner.lookup(id);
    owner.unbind(id);
    recipient.bind({id, item.keywords}, item);
    
    
    // Update both containers
    (const_cast<ItemController *>(this))->env2d.unbind(key_owner);
    (const_cast<ItemController *>(this))->env2d.bind(key_owner, owner);
    
    (const_cast<ItemController *>(this))->env2d.unbind(key_recipient);
    (const_cast<ItemController *>(this))->env2d.bind(key_recipient, recipient);
    
//        std::cout << "\n";
//        print_contentsOf(key_owner);
//        std::cout << "\n";
//        print_contentsOf(key_recipient);
}


template<typename Key>
size_t ItemController<Key>::itemsCreated() const noexcept {
    return this->items_created;
}


template<typename Key>
size_t ItemController<Key>::containerSize(Key key) const noexcept {
    if (this->env2d.exists(key)) {
        auto env = this->env2d.lookup(key);
        return env.size();
    }
    
    return 0;
}


}

#endif /* ItemController_cpp */
