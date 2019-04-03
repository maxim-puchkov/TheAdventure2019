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
#include "ItemController.h"
#include "Authenticator.h"

#include "print.h"


namespace items {
    
using auth::Authenticator;
using ItemIdentifier = Identifier;

static long iccc = 0;


/*!
 @class ItemController
 
 @brief Controlls location and ownership of all items in the world.
 
 
 */
template<typename K>
class ItemController {
public:

    using ContainerContent = Environment<ItemSearchKey, Item>;
    using Environment2d = Environment<K, ContainerContent>;
    
    
    
    /*! Properties of to-be-created items are set in the builder */
    const ItemBuilder builder = ItemBuilder();
    
    /*! Item Controller identifier */
    const Identifier controller_id;
    
    
    
    ItemController()
    :  controller_id(0), authenticator(Authenticator<ItemIdentifier>()) {
        this->init();
    }
    
    ItemController(const Authenticator<ItemIdentifier> &auth)
    : controller_id(auth.parent_id), authenticator(auth) {
        this->init();
    }
    
    
    ~ItemController() = default;

    
    
    

    
    
    
    
    /// deprecated Use createdIn(ckey)
    /* [[deprecated]] */ ItemIdentifier create(K ckey) const {
        //debug::print("A", ckey);
        
        // return this->createIn(ckey);
        
        
        if (!this->builder.validate()) {
            return this->controller_id;
        }
        
        
        // debug::print("B, ", ckey);
        
        (const_cast<ItemController *>(this))->created_items++;
        
        if (!this->env2d.exists(ckey)) {
            //debug::print("1. Allocating container environment for ", ck);
            //this->memory.allocs++;
            //debug::print("2");
            Environment<ItemSearchKey, Item> newContainer;
            //debug::print("3");
            ItemIdentifier item_id = this->requestIdentifier();
            auto item = this->builder.build(item_id);
            //debug::print("4");
            newContainer.bind(ItemSearchKey(item), item);
            //debug::print("5");
            this->env2d.bind(ckey, newContainer);
            //debug::print("6");
            
            return item.id;
        } else {
            //debug::print("1. Looking up existing container environment for ", ck);
            Environment<ItemSearchKey, Item> container = this->env2d.lookup(ckey);
            //debug::print("2");
            ItemIdentifier item_id = this->requestIdentifier();
            auto item = this->builder.build(item_id);
            //debug::print("3");
            container.bind(ItemSearchKey(item), item);
            //debug::print("4");
            this->update(ckey, container);
            //debug::print("5");
            
            return item.id;
        }
        

    }
    
    
    
    
    //void updateContainer(K ck) con
    
    void update(K ckey, Environment<ItemSearchKey, Item> &container) const {
        this->env2d.unbind(ckey);
        this->env2d.bind(ckey, container);
    }
    
    /// Create an item in the container
    ItemIdentifier updateContainer(K ckey, Environment<ItemSearchKey, Item> &container) const {
        return 0;
        
//        if (!this->builder.validate()) {
////            debug::print();
//            return this->controller_id;
//        }
//
//
//        //Environment<ItemSearchKey, Item> *container;
//        Environment<ItemSearchKey, Item> container;
//        if (!this->env2d.exists(ckey)) {
//            debug::print("1. Allocating container environment for ", ckey);
//            // container = this->memory.allocate(ckey);
//            this->allocs++;
//            container = Environment
//            this->env2d.bind(ckey, container);
//        } else {
//            debug::print("1. Looking up existing env2d for ", ckey);
//            container = this->env2d.lookup(ckey);
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
//        this->env2d.modify(ckey, container);
//        this->env2d.unbind(ckey);
//        this->env2d.bind(ckey, container);
        
        
//        debug::print("5. Item env2d updated: ", this->env2d.toString());
        
//        debug::print("6. env2d size: ", this->env2d.size());
        
        
//        this->memory.items_created++;
//        debug::print("7. Items created: ", this->memory.items_created);

        
        return controller_id;
        
    }


    /*! Search for all items matching a keyword */
    vector<ItemIdentifier> search(K ckey, const string &keyword) const {
        vector<Identifier> vec;
        auto env = this->env2d.lookup(ckey);
        
        for (auto element : env) {
            ItemSearchKey key = element.first;
            if (key.keywords.contains(keyword)) {
                vec.push_back(key.id);
            }
        }
        
        return vec;
    }
    
    
    /*! Lookup item object by its identifier */
    Item lookup(K ckey, ItemIdentifier id) const noexcept(false) {
        return this->env2d.lookup(ckey).lookup({id, {}});
    }
    
    
    /*! Lookup item object by its keywords */
    Item lookup(K ckey, const Keywords &keywords) const noexcept(false) {
        /// return this->env2d.lookup(ckey)->lookup({0, keywords});
        auto env = this->env2d.lookup(ckey);
        
        for (auto element : env) {
            ItemSearchKey key = element.first;
            // debug::print("3. ", key.id);
            if (key == ItemSearchKey{0, keywords}) {
                return element.second;
            }
        }
        
        throw std::invalid_argument("IC lookup");
    }
    
    
    /*! Determine if an item exists with an identifier exists in a container */
    bool exists(K ckey, ItemIdentifier id) const noexcept {
        if (this->env2d.exists(ckey)) {
            auto env = this->env2d.lookup(ckey);
            
            for (auto element : env) {
                ItemSearchKey key = element.first;
                if (key == ItemSearchKey{id, {}}) {
                    return true;
                }
            }
            
        }
        
        return false;
    }


    /*! Determine if an item exists with keywords exists in a container */
    bool exists(K ckey, const Keywords &keywords) const noexcept {
        if (this->env2d.exists(ckey)) {
            auto env = this->env2d.lookup(ckey);
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
    vector<ItemSearchKey> contentsOf(K ckey) const {
        auto env = this->env2d.lookup(ckey);
        vector<ItemSearchKey> vec;
        vec.reserve(env.size());
        
        for (auto &binding : env) {
            ItemSearchKey key = binding.first;
            vec.push_back(key);
        }
        
        return vec;
    }
    
    /*! Retrieve how many items are currently in a container */
    size_t containerSize(K ckey) const noexcept {
        if (this->env2d.exists(ckey)) {
            auto env = this->env2d.lookup(ckey);
            return env.size();
        }
        
        return 0;
    }
    
    
    /*! Reassign ownership of an item to the recipient */
    void reassign(K ckey_owner, K ckey_recipient, ItemIdentifier id) noexcept(false) {
        
        auto owner = this->env2d.lookup(ckey_owner);
        auto recipient = this->env2d.lookup(ckey_recipient);
        
        //
        // print_contentsOf(ckey_owner);
        // print_contentsOf(ckey_recipient);
        //
        
        Item item = owner.lookup(id);
        
        owner.unbind(id);
        recipient.bind({id, item.keywords}, item);
        
        this->env2d.unbind(ckey_owner);
        this->env2d.bind(ckey_owner, owner);
        
        this->env2d.unbind(ckey_recipient);
        this->env2d.bind(ckey_recipient, recipient);
        
        //
        // print_contentsOf(ckey_owner);
        // print_contentsOf(ckey_recipient);
        //
    }

    
    /*! Refer to container contents */
    ContainerContent& operator[](K ckey) noexcept(false) {
        return this->env2d.lookup(ckey);
    }
    
    
//    /*! Refer to container contents */
//    ContainerContent& operator[](K ckey) const noexcept(false) {
//        return this->env2d.lookup(ckey);
//    }
//

    
    /*! @return Total number of items created */
    unsigned int itemsCreated() const noexcept {
        return this->created;
    }
    

    
    
    
    
    
    
    

    
    
  
    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    // debug
    void display_all() {
        debug::print(this->env2d);
    }
    
    // debug print all items
    void print_contentsOf(K ckey) {
        for (auto &x : contentsOf(ckey)) {
            print("id ", ckey, ". ", x.toString());
        }
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
    
    
    /*! Generate unique id and build a new item */
    ItemIdentifier buildUniqueItem() const noexcept {
        return this->authenticator.generateUniqueIdentifier();
        //return this->builder.build(id);
    }
    
    /* * * * * * * * * * * *       Deprecated      * * * * * * * * * * * */
    
    
    
    
    
    
    
private:
    
    
    
    /*! All existing items are stored in the two-dimensional environment mapping
        a Container Key to Item Search Key to the Item instance */
    mutable Environment2d env2d;
    
    
    /*! Total count of created items */
    size_t created_items = 0;
    
    
    
    
    /*! Reqeust a unique identifier for an item */
    ItemIdentifier requestIdentifier() const noexcept {
        return this->authenticator.generateUniqueIdentifier();
    }
    
    
    /*! Generate search key to lookup item */
    ItemSearchKey generateSearchKey(Identifier item_id) const noexcept {
        return ItemSearchKey(item_id, this->builder.keywords);
    }
    
    
    /*! Remove an item from a container */
    bool removeItem(Environment<ItemSearchKey, Item> &owner, ItemIdentifier id) const noexcept {
        ItemSearchKey key(id);
        if (owner.exists(key)) {
            owner.unbind(key);
            return true;
        }
        
        return false;
    }
    
    


    /*! Local item authenticator */
    const Authenticator<ItemIdentifier> authenticator;
    
    void init() {
        //this-> = this->authenticator.parent_id;

        
        debug::prefix("ItemController");
        debug::print("ItemController created");
        
        iccc++;
        debug::print("<<< #", iccc, ", id", controller_id, " >>>");
        
    }
    
    //template<typename K, typename V>

//
//    void deallocateContainers() const noexcept(false) {
////        auto keys = this->env2d.keys();
////        while (!keys.empty()) {
////            this->memory.dealloc(keys.front());
////            keys.pop();
////        }
//        for (auto &binding : this->env2d) {
//            K key = binding.first;
//            Environment<ItemSearchKey, Item>env = binding.second;
//
//            this->env2d.unbind(key);
//            // this->memory.deallocate(env);
//        }
//    }
    
    /*! Keeps trackey of dynamic memory deallocations */
    //mutable ICMemory memory;
    
    
};

    

} /* namespace items */






//
///*!
// Create a new item in a container. If it is a new container,
// it will be created
//
// @param ckey container lookup key
//
// @return identifier of the created item
// if item was invalid (i.e. no keywords),
// id of the controller is returned
// */
//ItemIdentifier createIn(K ckey) const /* noexcept(false) */ {
//
//    // If specified item settings are invalid, it will not be built
//    if (!this->builder.validate()) {
//        return this->controller_id;
//    }
//
//    // Unique identifier and a search key {id, keywords} are
//    // generated for each item
//    ItemIdentifier item_id = this->requestIdentifier();
//    ItemSearchKey item_key = this->generateSearchKey(item_id);
//
//    // Item is saved in the container
//    this->env2d.lookup(ckey).bind(item_key, this->builder.build(item_id));
//    this->env2d.modify(ckey, std::move(this->env2d.lookup(ckey)));
//
//
//    //this->env2d = this->env2d[ckey];
//    //this->env2d[ckey].insert(ItemSearchKey(item)
//    // Item can be found by its id or one of the keywords
//    //this[ckey].bind(item_key, item);
//
//}


// create
//        if (!this->env2d.exists(ckey)) {
//            debug::print("1. Creating container environment for container key = ", ckey);
//            this->env2d.bind(ckey, Environment<ItemSearchKey, Item>());
//            debug::print("2. Bounnd ", ckey, " to ", " empty Environment<ItemSearchKey, Item>");
//        }
//
//this->env2d.lookup(ckey);
//this->env2d.i



//        if (!this->env2d.exists(ckey)) {
//
//            debug::print("1. Allocating container environment for ", ckey);
//            //this->memory.allocs++;
//            debug::print("2");
//            Environment<ItemSearchKey, Item> newContainer;
//            debug::print("3");
//            //auto item = this->buildUniqueItem();
//            ItemIdentifier item_id = this->requestIdentifier();
//            this->builder.build(id)
//            debug::print("4");
//
//
//
//            newContainer.bind(ItemSearchKey(item), item);
//            debug::print("5");
//
//            debug::print("6");
//
//
//
//
//            return item.id;
//
//        } else {
//
//            debug::print("1. Looking up existing container environment for ", ckey);
//            Environment<ItemSearchKey, Item> container = this->env2d.lookup(ckey);
//            debug::print("2");
//            auto item = this->buildUniqueItem();
//            debug::print("3");
//            container.bind(ItemSearchKey(item), item);
//            debug::print("4");
//            this->update(ckey, container);
//            debug::print("5");
//            return item.id;
//
//        }



#endif /* ItemController_h */
