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
#include "Constructor.h"
#include "Object.h"
#include "Item.h"
#include "ItemDescription.h"


using std::string;
using std::vector;
using namespace objects::typenames;



const unsigned int LINE_WIDTH = 80;
const unsigned int SHORT_DESCRIPTION_WIDTH = 20;



/**
 @class ItemConstructor
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemConstructor : public Constructor {
public:
    
    ItemConstructor();
    
    ~ItemConstructor();
    
    
    
    /// Create an item with provided input
    Item create();
    
    /// Reset current item construction
    void reset() override;
    
    /// - parameter keywords: Item's unique keywords
    void setKeywords(const std::set<Keyword> &keywords) override;
    
    /// Set item's description text
    void setDescription(const Text &description) override;
    
    /// Set collection of interactable commands
    void setExtras(const Extras &extras);
    
    
private:
    
    /// Clear all data members and reset to default value
    void clearAll();
    
    
    /// Generate next object identifier
    ObjectID nextUUID();
    
    
    // IC Data members
    std::set<Keyword> keywords;
    ItemDescription description;
    Extras extras; // additional actions of an item
    
    
    identity::UUID unique_identifiers;
    
};

#endif /* ItemConstructor_h */
