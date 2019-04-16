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
#include "ItemData.h"
#include "Builder.h"
#include "ItemBuilderConfiguration.h"


namespace items {

using builders::Builder;
using objects::AttributeValue;


/*!
  @class ItemBuilder (IB)
 
  @brief Creates customizable items
 
  @discussion
     Before creating a new item, specify its keywords (required)
        builder.setKeywords( {"keyword1", "keyword 2"} )

     Other optional properties may be changed
        •   .setDescription(string)
        •   .setActions( { {string, string}, {string, string}, ...} )
        •   .setAttributes( {int, int, ...})
 */
class ItemBuilder: public Builder {
public:
    
    /* Constructors */
    
    /*! ItemBuilder constructor, destructor */
    ItemBuilder() = default;
    ~ItemBuilder() override = default;
    
    
    
    
    /* Configurable item properties */
    
    mutable ItemBuilderConfiguration configuration;
    
    
    
    /*! Set item's unique keywords */
    void setKeywords(const vector<string> &keywords) const noexcept override;
    
    /*! Set item's short and long descriptions from source text */
    void setDescription(const string &text) const noexcept override;
    
    /*! Set item's interactable actions */
    void setActions(const vector<pair<string, string>> &actions) const noexcept override;
    
    /*! Set item's bonus attributes */
    void setAttributes(initializer_list<AttributeValue> values) const noexcept override;
    
    
    
    
    /* Builder Configuration */
    
    /*! Reset configuration to default values */
    void reset() const noexcept override;
    
    /*! Validate configuration integrity */
    bool validate() const noexcept override;
    
    
    
    
    /* Item Builder */
    
    /*!
     @function build
     Build using specified keywords, descriptions, and actions.
     Optionally, its original JSON identifier can be specified.
     */
    Item build(ItemIdentifier id) const;
    Item build(ItemIdentifier id, unsigned int json_id) const;

    /*! Add a new action */
    void addAction(Action &&action) const noexcept;
    
    
    
    
    /* * * Overloaded for convenience * * */
    
    void setDescription(const vector<string> &lines) const noexcept;
    
    void setItemProperties(const vector<string> &keywords,
                           const string &description,
                           const vector<pair<string, string>> &actions) const noexcept;

    void setItemProperties(const Keywords &keywords,
                           const Description &description,
                           const Actions &actions) const noexcept;
    
private:
    
    /*! Clear builder's settings and reset to default value */
    void clearAll() const;
    
};


} /* namespace items */

#endif /* ItemBuilder_h */
