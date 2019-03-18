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
#include "Description.h"
#include "KeywordSet.h"

using std::string;
using std::vector;


const unsigned int LINE_WIDTH = 80;
const unsigned int SHORT_DESCRIPTION_WIDTH = 20;



namespace objects {

/**
 @class ItemConstructor (IC)
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemConstructor : public Constructor {
public:
    
    ItemConstructor();
    
    ~ItemConstructor();
    
    
    
    /// Create an item with current settings
    Item create();
    
    /// Reset current item settings
    void reset() override;
    
    /// - parameter keywords: Item's unique keywords
    void setKeywords(const KeywordSet &keywords) override;
    
    /// Set item's description text
    void setDescription(const Description &description) override;
    
    /// Set collection of interactable commands
    void setExtras(const Extras &extras);
    
private:
    
    /// Clear all data members and reset to default value
    void clearAll();
    
    
    // Item Constructor Data members
    Identifier id;
    KeywordSet keywords;
    Description description;
    Extras extras; // additional actions of an item
    
};

}

#endif /* ItemConstructor_h */
