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

#include "Identifier.h"
#include "Constructor.h"
#include "Description.h"
#include "Object.h"


using std::string;
using std::vector;



namespace objects {




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
    
    
    /// Retrieve object's reference to keywords
    // KeywordSet& keywords() override;
    
    
    /// Display item's first keyword
    string brief() const override;
    
    
    /// Display detailed info
    string details() const override;
    
    
    bool hasKeyword(const Key &keyword) const {
        return this->keywords.contains(keyword);
    }
    
    /// Examine an Extra attribute of an item
    bool examine(const Key &keyword) const override;
    
    
//
//    Item& operator=(const Item &other) {
//        this->keywords = other.keywords;
//        this->description = other.description;
//        this->extras = other.extras;
//        return *this;
//    }
//
//
//    Item& operator=(Item &other) {
//        this->keywords = other.keywords;
//        this->description = other.description;
//        this->extras = other.extras;
//        return *this;
//    }
    
    KeywordSet keywords;


private:
    
    Identifier itemID;
    
    
    
    Description description;
    
    Extras extras;
    
};


}

#endif /* Item_h */
