//
//  Collection.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Collection_h
#define Collection_h

#include <string>
#include <unordered_set>
#include <functional>

#include "Object.h"
#include "Item.h"


namespace items {


/*!
 @class Collection
 
 @brief Game chests, bags, inventory
 
 Collection
 
 @warning Not used
 */
//template<typename T, unsigned int capacity>
class Collection : public Object {
public:
    
    /* Constructors */
    
    //Collection();
    
    ~Collection();
    
    Collection(const Item &container, unsigned int capacity);
    
    
    
    
    
    /* Mutable Structures */
    
    /// Set of keywords describing this item
    Keywords keywords;
    
    /// Formatted description text
    Description description;
    
    /// Interactable actions
    Actions actions;
    
    
    
    
    
    /* Object Interface */

    /// Retrieve object ID
    ItemIdentifier identifier() const override;
    
    /// Display item's first keyword
    Key brief() const override;
    
    /// Display detailed info
    Text toString() const override;
        
    /// Examine an Extra attribute of an item
    Text examine(const Key &keyword) const override;
    
    
    
    
    
    /* Set operations */
    
    bool insert(const Item &item);
    bool insert(ItemIdentifier id);
    
    bool erase(const Item &item);
    bool erase(ItemIdentifier id);
    
    bool contains(ItemIdentifier id) const;
    
    size_t size() const;
    
    
    
    
    
    /* Iterators */
    
    std::set<ItemIdentifier>::const_iterator begin() const;
    std::set<ItemIdentifier>::const_iterator end() const;

private:
    
    ItemIdentifier collectionID;
    
    Item container;
    
    unsigned int capacity;

    std::set<ItemIdentifier> set;
    
};


} /* namespace items */

#endif /* Collection_h */
