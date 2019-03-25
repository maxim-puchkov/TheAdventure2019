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

//#include "ObjectLibrary.pch"

// #include "Description.h"
// #include "KeywordSet.h"

using std::string;
using std::vector;


const unsigned int LINE_WIDTH = 80;
const unsigned int SHORT_DESCRIPTION_WIDTH = 20;




/**
 @class ItemBuilder (IB)
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemBuilder : public Builder {
public:
    
    ItemBuilder();

    /// Create an item with current settings
    Item create();

    /// Reset current item settings
    void reset() override;

    /// Set item's unique keywords
    void setKeywords(const vector<string> &keywords) override {
        this->keywords = KeywordSet(keywords);
    }

    /// Set item's description text
    void setDescription(const string &text) override {
        this->description = Description(text);
    }
    

    /// Set item's interactable actions
    void setActions(const vector<pair<string, string>> &actions) override {
        this->actions = Actions(actions);
    }
    
    // ~ItemBuilder() override;
    // void setKeywords(const KeywordSet &keywords) override;
    // void setDescription(const Description &description) override;

    // void setActions(const Actions &actions) override;
    
    
    
    bool ready = false;

private:

    /// Clear all data members and reset to default value
    void clearAll();



    // Item Constructor Data members
    Identifier id;
    KeywordSet keywords;
    Description description;
    Actions actions;
    
    // Extras extras; // additional actions of an item
    
};


#endif /* ItemBuilder_h */
