//
//  Item.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include "Object.h"


namespace objects {
inline namespace items {


/**
 @class Item
 
 @brief ...
 */
class Item : public Object {
public:
    
    /* Constructors */
    
    Item();
    
    /// Default item constructor with an object ID, identifying keywords,
    ///     item description, and extra actions.
    Item(Identifier id,
         const KeywordSet &keywords,
         const Description &description,
         const Actions &actions);
    
    ~Item();

    

    /* Mutable Structures */
    
    /// Set of keywords describing this item
    KeywordSet keywords;
    
    /// Formatted description text
    Description description;
    
    /// Interactable actions
    Actions actions;
    
    
    
    
    /* Object interface */
    
    /// Retrieve object ID
    Identifier id() const override;
    
    /// Display item's first keyword
    Key brief() const override;
    
    /// Display detailed info
    Text display() const override;
    
    /// Examine an Extra attribute of an item
    Text examine(const Key &keyword) const override;
    
    
    
    
    
    /* Operators */
    
    Item& operator=(Item &other);
    
    Item& operator=(const Item &other);
    
    

private:
    
    Identifier itemID;
    
};


} /* namespace items */
    
} /* namespace objects */






using objects::items::Item;

/*!
 @struct hash
 @discussion Item's hash function
 */
template<>
struct std::hash<Item> {
    std::size_t operator()(const Item &item) const;
};

#endif /* Item_h */
