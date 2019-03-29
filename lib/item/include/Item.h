//
//  Item.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include "items.hpp"


namespace items {


/**
 @class Item
 
 @brief ...
 */
class Item: public Object {
public:
    
    // using IdentifierTypename = Object::IdentifierTypename;
    
    /* Constructors */
    
    // !
//    Item();
    
    
    /// Default item constructor with identifying keywords,
    /// item description, and additional actions.
    Item(const Keywords &keywords,
         const Description &description,
         const Actions &actions);
    
    // !
//    Item(Identifier id,
//         const Keywords &keywords,
//         const Description &description,
//         const Actions &actions);
    
    
    ~Item() override;

    

    /* Mutable Structures */
    
    /// Set of keywords describing this item
    Keywords keywords;
    
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
    Text toString() const override;
    
    /// Examine an Extra attribute of an item
    Text examine(const Key &keyword) const override;
    
    
    
    
    
    /* Mutators */
    
    void setIdentifier(Identifier identifier) {
        this->itemID = identifier;
    }
    
    
    
    
    /* Operators */
    
    Item& operator=(Item &other);
    
    Item& operator=(const Item &other);
    
    

private:
    
    Identifier itemID;
    
};


} /* namespace items */

#endif /* Item_h */
