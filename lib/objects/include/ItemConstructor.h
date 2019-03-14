//
//  ItemConstructor.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ItemConstructor_h
#define ItemConstructor_h

#include <vector>
#include <string>
#include "Object.h"
#include "Item.h"
#include "ItemDescription.h"


using std::string;
using std::vector;

using objects::ObjectID;
using objects::Keywords;
using objects::Text;
using objects::Association;


const unsigned int LINE_WIDTH = 80;
const unsigned int SHORT_DESCRIPTION_WIDTH = 20;


/**
 @class
    ItemConstructor
 
 @description
    Constructs items with keywords and short/long descriptions.
 */
class ItemConstructor : public objects::Object {
public:
    
    ItemConstructor();
    
    ~ItemConstructor() override;
    
    
    
    /// Create an item with provided input
    Item create();
    
    /// Reset current item construction
    void reset() override;
    
    /// Set item's identifying keywords
    void setKeywords(const Keywords &keywords) override;
    
    /// Set item's description text
    void setDescription(const Text &description) override;
    
    
private:
    
    /// Clear all data members and reset to default value
    void clearAll();
    
    
    /// Generate next object identifier
    ObjectID nextUUID();
    
    
    // IC Data members
    Keywords keywords;
    ItemDescription description;
    Extras extras; // additional actions of an item
    
    
    identity::UUID ids;
    
};

#endif /* ItemConstructor_h */
