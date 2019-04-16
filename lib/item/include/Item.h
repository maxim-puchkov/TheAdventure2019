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

#include "ItemData.h"


namespace items {


/*!
 @class Item
 
 @brief ...
 */
class Item: public Object {
public:
    
    /*! Unique identifier */
    const ItemIdentifier id;
    
    /*! Item can store its ID used in a JSON input file */
    const int json_id;
    
    
    /*!
     Item constructor for building game items
     
     @param keywords    Set of identifying keywords
     @param description Item description text
     @param actions     Actions associated with this item
     */
    Item(ItemIdentifier id,
         const Keywords &keywords,
         const Description &description,
         const Actions &actions);
    
    Item(ItemIdentifier id,
         int json_id,
         const Keywords &keywords,
         const Description &description,
         const Actions &actions);
    
    Item(Item &&other) noexcept;
    
    
    ~Item() override = default;
    
    
    
    
    
    /* Object interface */
    
    /*! Unique identifier assigned to this object */
    ItemIdentifier identifier() const override;
    
    /*! Item's brief description containing its keywords */
    Text info() const override;
    
    /*! Full text of the description */
    Text details() const override;
    
    
    
    /*! Examine an action to see its description @warning undefined */
    Text examine(const Text &keyword) const override;
    
    
    
    /*! Represent this object as string */
    Text toText() const override;
    
    /*! Check if object has additional actions */
    bool isInteractable() const override;
    
    /*! Check if object provides bonus attributes when equipped */
    bool isEquipable() const override;
    
    
    
    
    /* Item data */
    
    /*! Several keywords describing this item */
    Keywords keywords;
    
    /*! Item's description text */
    Description description;
    
    /*! Interactable actions */
    Actions actions;
    
    /*! Bonus attributes */
    ItemAttributes attributes;
    
    
    
    
    /* Operators */
    
    Item& operator=(Item &&other) noexcept;
    Item& operator=(const Item &other);
    
    bool operator==(Item &other) const;
    bool operator==(const Item& other) const;
    
    bool operator!=(Item &other) const;
    bool operator!=(const Item& other) const;
    
private:
    
    
    
};


} /* namespace items */





namespace std {

using items::Item;


/*!
 @struct hash
 @discussion Item's hash function
 
 @ignore
 */
template<>
struct hash<Item> {
    size_t operator()(const Item &item) const;
};


} /* namespace std */

#endif /* Item_h */
