//
//  ICData.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ICData
//
//  Created by mpuchkov on 2019-04-23. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ICData_h
#define ICData_h

#include "items.hpp"
#include "Item.h"
#include "ItemSearchKey.h"

namespace items {


template<typename Key>
class ICContainers {
public:
    
    using Container = Environment<ItemSearchKey, Item>;
    using Container2d = Environment<Key, Container>;
    
    
    /*! Search for all items matching a keyword in a container */
    vector<ItemIdentifier> search(Key key, const Keyword &keyword) const noexcept;
    
    
    /*!
     @function exists
     Check if an item exists in a container
     @param id Unique identifier of the particular item
     @param keywords Keywords of the particular item
     */
    bool exists(Key key, ItemIdentifier id) const noexcept;
    bool exists(Key key, const Keywords &keywords) const noexcept;
    
    
    /*!
     @function lookup
     Lookup symbolic item object by its identifier or a matching keyword
     @throws std::invalid_argument if item does not exist
     */
    Item lookup(Key key, ItemIdentifier id) const noexcept(false);
    Item lookup(Key key, const Keywords &keywords) const noexcept(false);
    
    
    /*! Change ownership */
    void reassign(Key key_owner,
                  Key key_recipient,
                  ItemIdentifier id) const;
    
    
    /*!
     Contents of a container
     @return Vector of {id, keywords} pairs
     */
    vector<ItemSearchKey> contentsOf(Key key) const;
    
    /*! @return Quantity of items in a container */
    size_type containerSize(Key key) const noexcept;
    
    /*! @return Total number of items created in the world */
    size_type itemsCreated() const noexcept;
    
    /*! Update container storage */
    void update(Key key, Container &container) const;
    
    
    
    void allocate(Key key) const {
        if (this->isAllocated(key)) {
            // throw
            return;
        }
        
        this->env2d.bind(key, Container());
    }
    
    bool isAllocated(Key key) const noexcept {
        return this->env2d.exists(key);
    }
    
    Container content(Key key) const noexcept {
        return this->env2d.lookup(key);
    }
    
    
    /*! Remove an item from its owner */
    bool removeItem(Container &owner,
                    ItemIdentifier id) const noexcept {
        
        ItemSearchKey key(id);
        if (owner.exists(key)) {
            owner.unbind(key);
            return true;
        }
        
        return false;
    }
    
    
    // Display for debugging
    Text detailsOfList(Key key, const vector<ItemIdentifier> &item_list) const;
    Text detailsOfList(const vector<ItemSearchKey> &item_list) const noexcept;
    
    
private:
    
    /*! All existing items are stored in the two-dimensional environment */
    mutable Container2d env2d;
    
    /*! Quantity of items created by this builder */
    mutable size_type items_created = 0;
    
};


} /* namespace items */

#endif /* ICData_h */
