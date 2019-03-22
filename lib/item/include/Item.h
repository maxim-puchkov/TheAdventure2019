//
//  Item.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include <string>
#include <vector>
#include <functional>
#include <cstdint>
#include <sstream>
#include <unordered_set>

#include "Object.h"


// temp
using std::string;
using std::vector;

namespace objects {
inline namespace items {


/**
 @class Item
 
 @brief ...
 */
class Item : public Object {
public:
    
    /// Default item constructor with an object ID, identifying keywords,
    ///     item description, and extra actions.
    Item(Identifier id,
         const KeywordSet &keywords,
         const Description &description,
         const Extras &extras);
    
    
    /*  *  *  *  *  *  *  *  */
    Item() { }
    
    Item(int i)
    { /* print(i); */ }
    
    Item(const KeywordSet &keywords, const Description &description)
    : keywords(keywords), description(description)
    { /* throw 4; */ }
    
    ~Item() { }
    /*  *  *  *  *  *  *  *  */
    
    
    
    /// Retrieve object ID
    Identifier id() const override;
    
    
    /// Set of keywords describing this item
    KeywordSet keywords;
    
    
    /// Display item's first keyword
    Key brief() const override;
    
    
    /// Display detailed info
    Text details() const override;
    
    
    Extras actions() const override {
        return extras;
    }
    
    
    /// Examine an Extra attribute of an item
    bool examine(const Key &keyword) const override;
    
    
    /// Assignment
    Item& operator=(const Item &other); /* undefined */
    Item& operator=(Item &other); /* undefined */
    
    
    // #rename
    bool hasKeyword(const Key &keyword) const;

private:
    
    Identifier itemID;
    
    Description description;
    
    Extras extras; /* undefined */
    
};


} /* namespace items */
} /* namespace objects */

#endif /* Item_h */
