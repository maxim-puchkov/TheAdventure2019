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

using builders::Builder;


namespace items {
    

/**
 @class ItemBuilder (IB)
 
 @brief Constructs items with keywords, descriptions,
        and extra commands
 */
class ItemBuilder : public Builder {
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
    
    // Each builder maintains list of created objects
    // vector<Object *> list() const noexcept override;
    
    // Object::IdentifierTypename requestIdentifier() noexcept override;
    
    
    // temp
    bool ready = false;

private:

    //Object::IdentifierTypename identify(Object *object) noexcept override;
    
    /// Clear all data members and reset to default value
    void clearAll() const;
    
    
    /* Item Constructor Data members */
    mutable Identifier itemID;
    mutable Keywords keywords;
    mutable Description description;
    mutable Actions actions;
    
    
    /* Each object is authentic and stored inside the builder */
    // Authenticator<Object::IdentifierTypename> authenticator;
    // vector<Object *> created;
    // Environment<Object::IdentifierTypename, Object *> env;
    
};


} /* namespace items */

#endif /* ItemBuilder_h */
