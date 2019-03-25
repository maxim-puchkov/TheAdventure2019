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
    
    Item()
    { }
    
    /// Default item constructor with an object ID, identifying keywords,
    ///     item description, and extra actions.
    Item(Identifier id,
         const KeywordSet &keywords,
         const Description &description,
         const Actions &actions);

    //Item(const KeywordSet &keywords, const Description &description)
    //: keywords(keywords), description(description)
    //{ /* throw 4; */ }
    
    ~Item() { }

    
    /// Retrieve object ID
    Identifier id() const override;
    
    
    /// Set of keywords describing this item
    KeywordSet keywords;
    
    Description description;
    
    Actions actions;
    
    
    /// Display item's first keyword
    Key brief() const override;
    
    
    /// Display detailed info
    Text display() const override;
    
    
//    Actions allActions() const override {
//        return this->actions;
//    }
    
    
    /// Examine an Extra attribute of an item
    Text examine(const Key &keyword) const override;
    
    
    /// Assignment
    Item& operator=(const Item &other); /* undefined */
    Item& operator=(Item &other); /* undefined */
    
    
    // #rename
    bool hasKeyword(const Key &keyword) const;

private:
    
    Identifier itemID;
    
};


} /* namespace items */
    
} /* namespace objects */


using objects::items::Item;

template<>
struct std::hash<Item> {
    std::size_t operator()(const Item &item) const;
};

#endif /* Item_h */
