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


namespace objects {
using objects::Keywords;
using objects::Description;


inline namespace items {
/*!
 @class Collection
 
 @brief Game chests, bags, inventory
 
 Collection
 */
//template<typename T, unsigned int capacity>
class Collection : public Object {
public:
    
    /* Constructors */
    
    Collection();
    
    ~Collection();
    
    Collection(const Item &item, unsigned int capacity);
    
    
    
    
    
    /* Mutable Structures */
    
    /// Set of keywords describing this item
    Keywords keywords;
    
    /// Formatted description text
    Description description;
    
    /// Interactable actions
    Actions actions;
    
    
    
    
    
    /* Object Interface */

    /// Retrieve object ID
    Identifier id() const override;
    
    /// Display item's first keyword
    Key brief() const override;
    
    /// Display detailed info
    Text display() const override;
        
    /// Examine an Extra attribute of an item
    Text examine(const Key &keyword) const override;
    
    
    
    
    
    /* Set operations */
    
    bool insert(const Item &item);
    
    bool erase(const Item &item);
    
    size_t size();

private:
    
    Identifier collectionID;
    
    Item container;
    
    unsigned int capacity;

    std::set<Identifier> set;
    
};


} /* namespace items */


} /* namespace objects */

#endif /* Collection_h */
