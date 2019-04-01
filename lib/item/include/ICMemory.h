//
//  ICMemory.h
//  Objects: Item
//  com.maximpuchkov.Objects.Objects.ICMemory
//
//  Created by mpuchkov on 2019-03-31. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ICMemory_h
#define ICMemory_h

#include "items.hpp"
#include "Item.h"
#include "ItemSearchKey.h"
#include "bad_dealloc.h"


namespace items {
    

/// Will be changed
struct ICMemory {
public:
    
    
//    ICMemory()
//    : allocs(0), deallocs(0), items_created(0)
//    { }

//
//    size_t allocations();
//
//    size_t deallocations();
//
//    size_t itemsCreated();
    
//private:

    
    void validate() const noexcept(false) {
        if (this->allocs != this->deallocs) {
            throw bad_dealloc("ItemController memory deallocation exception");
        }
    }
    
    template<typename T>
    Environment<ItemSearchKey, Item> allocate(T t) noexcept {
        //         auto *container =
        //        this->env2d.bind(t, containerEnv);
        this->allocs++;
        // return new Environment<ItemSearchKey, Item>();;
        return Environment<ItemSearchKey, Item>();;
    }
    
    
    //template<typename K, typename V>
    void deallocate(Environment<ItemSearchKey, Item> &container) noexcept(false) {
        //Environment<ItemSearchKey, Item> *containerEnv = this->env2d.lookup(ck);
        //this->env2d.unbind(ck);
        this->deallocs++;
        //delete container;
    }

    
    
    size_t allocs = 0;
    size_t deallocs = 0;
    size_t items_created = 0;
    
};

}

#endif /* ICMemory_h */
