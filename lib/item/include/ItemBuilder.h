//
//  ItemBuilder.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ItemBuilder_h
#define ItemBuilder_h

#include <vector>
#include <string>

#include "Builder.h"
#include "Item.h"

using namespace objects;






/**
 @class ItemBuilder (IB)
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemBuilder : public Builder {
public:
    
    /* Constructors */
    
    ItemBuilder();

    
    
    
    
    
    /* Create / Reset */
    
    /// Create an item with current settings
    Item create();

    /// Reset current item settings
    void reset() override;
    
    
    
    
    
    /* Set item's properties */

    /// Set item's unique keywords
    void setKeywords(const vector<string> &keywords) override;

    /// Set item's description text
    void setDescription(const string &text) override;
    
    /// Set item's interactable actions
    void setActions(const vector<pair<string, string>> &actions) override;
    
    
    // temp
    bool ready = false;

private:

    /// Clear all data members and reset to default value
    void clearAll();

    
    
    /* Item Constructor Data members */
    Identifier id;
    Keywords keywords;
    Description description;
    Actions actions;
    
};


#endif /* ItemBuilder_h */
