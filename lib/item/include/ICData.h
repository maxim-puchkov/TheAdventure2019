//
//  ICStore.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ICStore
//
//  Created by mpuchkov on 2019-04-16. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ICStore_h
#define ICStore_h


template<typename Key>
class ICStore {
public:
    
    /*! Search for all items matching a keyword in a container */
    vector<ItemIdentifier> search(Key key, const string &keyword) const noexcept;
    
    /*!
     @function exists
     Check if an item exists in a container
     @param id Unique identifier of the particular item
     @param keywords Keywords of the particular item
     */
    bool exists(Key key, ItemIdentifier id) const noexcept;
    bool exists(Key key, const Keywords &keywords) const noexcept;
    
    
    /*! @function lookup
     Lookup symbolic item object by its identifier or a matching keyword
     @warning  noexcept(false) */
    Item lookup(Key key, ItemIdentifier id) const noexcept(false);
    Item lookup(Key key, const Keywords &keywords) const noexcept(false);
    
    
    
    
    
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
    
    /*! Update container storage */
    void update(Key key, Container &container) const;
    
    //template<template<typename, typename> class KeyContent>
    //void update(KeyContent<Key,
    
private:
    
    /*! All existing items are stored in the two-dimensional environment */
    Container2d env2d;
    
    /*! Quantity of items created by this builder */
    std::size_t items_created = 0;
    
};


#endif /* ICStore_h */
