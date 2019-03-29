//
//  ItemBuilder.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ItemBuilder_h
#define ItemBuilder_h

#include "Item.h"
#include "Builder.h"


namespace items {

using builders::Builder;


/**
 @class ItemBuilder (IB)
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemBuilder: public Builder {
public:
    
    /* Constructors */
    
    ItemBuilder();
    
    ~ItemBuilder() override;

    
    
    
    
    /* Create / Reset */
    
    /// Create an item with current settings
    Item build() const;

    /// Reset current item settings
    void reset() const noexcept override;
    
    
    
    
    
    /* Set item's properties */

    // Set item's unique keywords
    void setKeywords(const vector<string> &keywords) const noexcept override;

    // Set item's description text
    void setDescription(const string &text) const noexcept override;
    
    // Set item's interactable actions
    void setActions(const vector<pair<string, string>> &actions) const noexcept override;
    
    /// Add a new action
    void addAction(Action &&action) const noexcept;

private:
    
    /// Clear all data members and reset to default value
    void clearAll() const;
    
    /* Item's data members */
    mutable Keywords keywords;
    mutable Description description;
    mutable Actions actions;
    
};


} /* namespace items */

#endif /* ItemBuilder_h */
