//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"


namespace items {


/* Builder Interface */

void ItemBuilder::reset() const noexcept {
    this->clearAll();
}

bool ItemBuilder::validate() const noexcept {
    return (!this->configuration.keywords.empty());
}


void ItemBuilder::setKeywords(const vector<string> &keywords) const noexcept {
    this->configuration.keywords = Keywords(keywords);
}

void ItemBuilder::setDescription(const string &text) const noexcept {
    this->configuration.description = Description(text);
}


void ItemBuilder::setActions(const vector<pair<string, string>> &actions) const noexcept {
    this->configuration.actions = Actions(actions);
}

void ItemBuilder::addAction(Action &&action) const noexcept {
    this->configuration.actions.add(std::move(action));
}


void ItemBuilder::setAttributes(initializer_list<AttributeValue> values) const noexcept {
    this->configuration.attributes = ItemAttributes(values);
}




/* Building items */

Item ItemBuilder::build(ItemIdentifier id) const {
    Item item(id,
              this->configuration.keywords,
              this->configuration.description,
              this->configuration.actions);
    this->reset();
    return item;
}
    
Item ItemBuilder::build(ItemIdentifier id, unsigned int json_id) const {
    Item item(id,
              json_id,
              this->configuration.keywords,
              this->configuration.description,
              this->configuration.actions);
    this->reset();
    return item;
}




/**/

void ItemBuilder::setDescription(const vector<string> &lines) const noexcept {
    this->configuration.description = Description(lines);
}


void ItemBuilder::setItemProperties(const vector<string> &keywords,
                                    const string &description,
                                    const vector<pair<string, string>> &actions) const noexcept {
    this->configuration.keywords = Keywords(keywords);
    this->configuration.description = Description(description);
    this->configuration.actions = Actions(actions);
}


void ItemBuilder::setItemProperties(const Keywords &keywords,
                                    const Description &description,
                                    const Actions &actions) const noexcept {
    this->configuration.keywords = keywords;
    this->configuration.description = description;
    this->configuration.actions = actions;
}




/* * *   Private   * * */

void ItemBuilder::clearAll() const {
//    this->configuration.reset();
//    
//    this->configuration.keywords.clear();
//    this->configuration.keywords = EMPTY_KEYS;
//    
//    this->configuration.description.clear();
//    this->configuration.description = DEF_DESC;
//    
//    this->configuration.actions.clear();
//    this->configuration.actions = DEF_ACTS;
//    
//    this->configuration.attributes.clear();
}


} /* namespace items */
