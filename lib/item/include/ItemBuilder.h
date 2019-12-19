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

inline namespace builder_defaults {
    const Keywords EMPTY_KEYS{};
    const Description DEF_DESC{"No description"};
    const Actions DEF_ACTS{{}};
}


/*!
 @class ItemBuilder (IB)
 
 @brief Creates items with keywords, descriptions, and additional actions
 */
class ItemBuilder: public Builder {
public:
    
    /// ItemBuilder constructor
    ItemBuilder();
    /// ItemBuilder destructor
    ~ItemBuilder() override;

    
    
    
    
    /* Builder Interface */
    
    /// Reset current item settings
    void reset() const noexcept override;
    /// Validate current settings
    bool validate() const noexcept override;
    /// Set item's unique keywords
    void setKeywords(const vector<string> &keywords) const noexcept override;
    /// Set item's description text
    void setDescription(const string &text) const noexcept override;
    /// Set item's interactable actions
    void setActions(const vector<pair<string, string>> &actions) const noexcept override;
    
    
    
    
    
    /* Item Builder */
    
    /* Item's data members */
    mutable Keywords keywords;
    mutable Description description;
    mutable Actions actions;
    
	/// Build using specified keywords, descriptions, and actions
    Item build(ItemIdentifier id) const;
    /// Build using specified keywords, descriptions, and actions, and original ID
    Item build(ItemIdentifier id, unsigned int json_id) const;

    /// Add a new action
    void addAction(Action &&action) const noexcept;
    /*! Overload for convenience */
    void setDescription(const vector<string> &lines) const noexcept;
    /*! Overload for convenience */
    void setItemProperties(const vector<string> &keywords,
                           const string &description,
                           const vector<pair<string, string>> &actions) const noexcept;
    /*! Overload for convenience */
    void setItemProperties(const Keywords &keywords,
                           const Description &description,
                           const Actions &actions) const noexcept;
    
private:
    
    /*! Clear builder's settings and reset to default value */
    void clearAll() const;
    
};


} /* namespace items */

#endif /* ItemBuilder_h */
