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

// #include "Description.h"
// #include "KeywordSet.h"

using std::string;
using std::vector;


const unsigned int LINE_WIDTH = 80;
const unsigned int SHORT_DESCRIPTION_WIDTH = 20;



namespace objects {


/**
 @class ItemBuilder (IB)
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemBuilder : public Builder {
public:
    
    ItemBuilder();
    
    ~ItemBuilder() override;
    
    
    
    /// Create an item with current settings
    Item create();
    
    /// Reset current item settings
    void reset() override;
    
    /// - parameter keywords: Item's unique keywords
    void setKeywords(const KeywordSet &keywords) override;
    
    /** @ignore */
    void setKeywords(const vector<Key> &vs) {
        KeywordSet keyw(vs);
        this->setKeywords(keyw);
    }
    
    /// Set item's description text
    void setDescription(const Description &description) override;
    void setDescription(const string &text) {
        this->setDescription(Description(text));
    }
    
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


} /* namespace objects */

#endif /* ItemBuilder_h */
