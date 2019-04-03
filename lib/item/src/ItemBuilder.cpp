//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"


namespace items {


/* Constructors */

ItemBuilder::ItemBuilder() {
    this->reset();
}


ItemBuilder::~ItemBuilder()
{ }





/* Builder Interface */

void ItemBuilder::reset() const noexcept {
    this->clearAll();
}


bool ItemBuilder::validate() const noexcept {
    return !this->keywords.empty();
}


void ItemBuilder::setKeywords(const vector<string> &keywords) const noexcept {
    this->keywords = Keywords(keywords);
}


void ItemBuilder::setDescription(const string &text) const noexcept {
    this->description = Description(text);
}


void ItemBuilder::setActions(const vector<pair<string, string>> &actions) const noexcept {
    this->actions = Actions(actions);
}
    
    
void ItemBuilder::addAction(Action &&action) const noexcept {
    this->actions.add(std::move(action));
}





/* Item Builder */

Item ItemBuilder::build(ItemIdentifier id) const {
    Item item(id, keywords, description, actions);
    this->reset();
    return item;
}


void ItemBuilder::setDescription(const vector<string> &lines) const noexcept {
    this->description = Description(lines);
}


void ItemBuilder::setItemProperties(const vector<string> &keywords,
                                    const string &description,
                                    const vector<pair<string, string>> &actions) const noexcept {
    this->keywords = Keywords(keywords);
    this->description = Description(description);
    this->actions = Actions(actions);
}


void ItemBuilder::setItemProperties(const Keywords &keywords,
                                    const Description &description,
                                    const Actions &actions) const noexcept {
    this->keywords = keywords;
    this->description = description;
    this->actions = actions;
}




/* * *   Private   * * */

void ItemBuilder::clearAll() const {
    this->keywords.clear();
    this->keywords = EMPTY_KEYS;
    
    this->description.clear();
    this->description = DEF_DESC;
    
    this->actions.clear();
    this->actions = DEF_ACTS;
}


} /* namespace items */
