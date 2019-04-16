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


//template<typename Key>
//ItemController<Key>::ItemController()
//{ }
    



/* Create */
    
template<typename Key>
ItemIdentifier ItemController<Key>::create(Key key) const noexcept {
    return this->create(key, -1);
}

template<typename Key>
ItemIdentifier ItemController<Key>::create(Key key, int json_id) const noexcept {
    
    // Validate building options
    if (!this->builder.validate()) {
        return this->controller_id;
    }
    
    
    // Create a new container if it does not exist
    if (!this->env2d.exists(key)) {
        Container emptyContainer;
        (const_cast<ItemController *>(this))->env2d.bind(key, emptyContainer);
    }
    
    
    // Lookup container by its search key
    Container container = this->env2d.lookup(key);
    
    
    // Build an item with unique identifier and put it in the container
    Item item = this->buildUniqueItem();
    container.bind(ItemSearchKey(item), item);
    
    
    // Update all items and number of created items
    this->update(key, container);
    (const_cast<ItemController *>(this))->items_created++;
    
    
    return item.id;
    
}




/* Search, lookup, and existance */

/*!
 @function search (safe)
 Find identifiers of all items in a container matching specified keyword.
 */
template<typename Key>
vector<ItemIdentifier>
ICContainerStorage<Key>::search(Key key,
                                const string &keyword) const noexcept {
    
    if (!this->env2d.exists(key)) {
        return {};
    }
    
    vector<ItemIdentifier> vec{};
    auto env = this->env2d.lookup(key);
    
    for (auto element : env) {
        ItemSearchKey key = element.first;
        if (key.keywords.contains(keyword)) {
            vec.push_back(key.id);
        }
    }
    
    return vec;
    
}




/*!
 @function exists (safe)
 Check if item exists in a container
 @note noexcept - Never throws
 */
template<typename Key>
bool ICContainerStorage<Key>::exists(Key key,
                                     ItemIdentifier id) const noexcept {
    if (this->env2d.exists(key)) {
        auto env = this->env2d.lookup(key);
        
        for (auto &element : env) {
            ItemSearchKey key = element.first;
            if (key == ItemSearchKey{id, {}}) {
                return true;
            }
        }
        
    }
    
    return false;
}

template<typename Key>
bool ICContainerStorage<Key>::exists(Key key,
                                     const Keywords &keywords) const noexcept {
    if (this->env2d.exists(key)) {
        auto env = this->env2d.lookup(key);
        
        for (auto &binding : env) {
            ItemSearchKey key = binding.first;
            if (key == ItemSearchKey{0, keywords}) {
                return true;
            }
        }
        
    }
    
    return false;
}




/*!
 @function lookup (unsafe)
 Lookup symbolic data for specified item. Item value can only be looked up if
 the search key is defined. Checking if item exists is recommended prior to lookup.
 @throw invalid_argument Exception is thrown if attempting to look up value bound to an undefined search key.
 */
template<typename Key>
Item ICContainerStorage<Key>::lookup(Key key,
                                     ItemIdentifier id) const noexcept(false) {
    return this->env2d.lookup(key).lookup({id, {}});
}


template<typename Key>
Item ICContainerStorage<Key>::lookup(Key key,
                                     const Keywords &keywords) const noexcept(false) {
    auto env = this->env2d.lookup(key);
    
    for (auto &binding : env) {
        ItemSearchKey key = binding.first;
        if (key == ItemSearchKey{0, keywords}) {
            return binding.second;
        }
    }
    
    throw std::invalid_argument("IC lookup");
}





template<typename Key>
vector<ItemSearchKey> ICContainerStorage<Key>::contentsOf(Key key) const {
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
void ICContainerStorage<Key>::reassign(Key key_owner,
                                   Key key_recipient,
                                   ItemIdentifier id) const {
    
    // - TODO: Refactor Unnecessary Repeats & Branching

    
    // Create a new container if it does not exist
    if (!this->env2d.exists(key_owner)) {
        Container emptyContainer;
        (const_cast<ICContainerStorage *>(this))->env2d.bind(key_owner, emptyContainer);
    }
    // Create a new container if it does not exist
    if (!this->env2d.exists(key_recipient)) {
        Container emptyContainer;
        (const_cast<ICContainerStorage *>(this))->env2d.bind(key_recipient, emptyContainer);
    }
    
    
    // Find containers of owner and recipient
    auto owner = this->env2d.lookup(key_owner);
    auto recipient = this->env2d.lookup(key_recipient);
    
    // Find the item and change its owner
    Item item = owner.lookup(id);
    owner.unbind(id);
    recipient.bind({id, item.keywords}, item);
    
    this->containers.updateList({{key_owner, owner}, {key_recipient, recipient}});
    
//
//    // - TODO: Copies
//    // Update both containers
//    (const_cast<ItemController *>(this))->env2d.unbind(key_owner);
//    (const_cast<ItemController *>(this))->env2d.bind(key_owner, owner);
//
//    (const_cast<ItemController *>(this))->env2d.unbind(key_recipient);
//    (const_cast<ItemController *>(this))->env2d.bind(key_recipient, recipient);
    
//        std::cout << "\n";
//        print_contentsOf(key_owner);
//        std::cout << "\n";
//        print_contentsOf(key_recipient);
}


template<typename Key>
std::size_t ICContainerStorage<Key>::itemsCreated() const noexcept {
    return this->items_created;
}


template<typename Key>
std::size_t ICContainerStorage<Key>::containerSize(Key key) const noexcept {
    if (this->env2d.exists(key)) {
        auto env = this->env2d.lookup(key);
        return env.size();
    }
    
    return 0;
}

template<typename Key>
void ICContainerStorage<Key>::update(Key key, Container &container) const {
    (const_cast<ICContainerStorage *>(this))->env2d.unbind(key);
    (const_cast<ICContainerStorage *>(this))->env2d.bind(key, container);
}










template<typename Key>
Text ICContainerStorage<Key>::detailsOfList(Key key, const vector<ItemIdentifier> &vec) const {
    object_ostream stream;
    
    stream << "Listing items:\n";
    for (auto &id : vec) {
        stream << '\t' << this->env2d.lookup(key).lookup(id).toString() << '\n';
    }
    
    return stream.str();
}
    
    
template<typename Key>
Text ICContainerStorage<Key>::detailsOfList(const vector<ItemSearchKey> &vec) const noexcept {
    object_ostream stream;
    
    stream << "Listing items:\n";
    for (auto &skey : vec) {
        stream << '\t' << skey.toString() << '\n';
    }
    
    return stream.str();
}


} /* namespace items */

#endif /* ItemController_cpp */
