//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"
#include "Tools.h"


namespace items {


/* Constructors */

ItemBuilder::ItemBuilder()
: keywords(Keywords()),
description(Description()),
actions(Actions())
{
    debug::PrefixMessage = "ItemBuilder";
    debug::print("Item builder created.");
}


ItemBuilder::~ItemBuilder() {
    debug::print("Item builder destroyed.");
}





/* Set Properties */

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





/* Create / Reset */

Item ItemBuilder::build(Identifier id) const {
    debug::print("Creating a new item...");
    Item item(id, keywords, description, actions);
    this->reset();
    return item;
}


void ItemBuilder::reset() const noexcept {
    this->clearAll();
}


void ItemBuilder::setDescription(const vector<string> &lines) const noexcept {
    this->description = Description(lines);
}





/* * *   Private   * * */

void ItemBuilder::clearAll() const {
    this->keywords.clear();
    this->keywords = DEF_KEYS;
    
    this->description.clear();
    this->description = DEF_DESC;
    
    this->actions.clear();
    this->actions = DEF_ACTS;
}


} /* namespace items */
