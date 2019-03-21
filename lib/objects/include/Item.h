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

#include "Builder.h"
#include "Description.h"
#include "Object.h"


using std::string;
using std::vector;



namespace objects {
    namespace data {


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
    
    
    /// Retrieve object ID
    Identifier id() const override;
    
    
    /// Set of keywords describing this item
    KeywordSet keywords;
    
    
    /// Display item's first keyword
    string brief() const override;
    
    
    /// Display detailed info
    string details() const override;
    
    
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

    }
}

#endif /* Item_h */
