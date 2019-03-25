//
//  ItemBuilder.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ItemBuilder_h
#define ItemBuilder_h

#include "Builder.h"
#include "Item.h"
#include "Authenticator.h"

using namespace objects;
using auth::Authenticator;


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
    void reset() noexcept override;
    
    
    
    
    
    /* Set item's properties */

    // Set item's unique keywords
    void setKeywords(const vector<string> &keywords) noexcept override;

    // Set item's description text
    void setDescription(const string &text) noexcept override;
    
    // Set item's interactable actions
    void setActions(const vector<pair<string, string>> &actions) noexcept override;
    
    // Each builder maintains list of created objects
    vector<Object *> list() const noexcept override;
    
    Object::IdentifierTypename requestIdentifier() noexcept override;
    
    
    // temp
    bool ready = false;

private:

    /// Clear all data members and reset to default value
    void clearAll();
    
    
    /* Item Constructor Data members */
    Object::IdentifierTypename id;
    Keywords keywords;
    Description description;
    Actions actions;
    
    
    /* Each object is authentic and stored inside the builder */
    // Authenticator<Object::IdentifierTypename> authenticator;
    vector<Object *> created;
    
};


#endif /* ItemBuilder_h */
