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


/*!
 @class Item
 
 @brief ...
 */
class Item: public Object {
public:
    
    /*! Unique identifier */
    const Identifier id;
    
    
    /*!
     Item constructor for building game items
     
     @param keywords    Set of identifying keywords
     @param description Item description text
     @param actions     Actions associated with this item
     */
    Item(Identifier id,
         const Keywords &keywords,
         const Description &description,
         const Actions &actions);
    
    ~Item() override;
    
    
    
    
    
    /* Object interface */
    
    /*! Unique identifier assigned to this object */
    Identifier identifier() const override;
    
    /*! Display item's short description */
    Text brief() const override;
    
    /*! Represent this object as string */
    Text toString() const override;
    
    /*! Examine an action to see its description @warning undefined */
    Text examine(const Key &keyword) const override;
    
    
    
    
    
    /* Item data */
    
    /*! Set of keywords describing this item */
    Keywords keywords;
    
    /*! Formatted description text */
    Description description;
    
    /*! Interactable actions */
    Actions actions;
    
    
    
    
    
    /* Modifiers */
    
    void setIdentifier(Identifier identifier) {
        // this->itemID = identifier;
    }
    
    
    
    
    
    /* Operators */
    
    Item& operator=(Item &other);
    Item& operator=(const Item &other);
    
private:
    
};


} /* namespace items */

#endif /* Item_h */
