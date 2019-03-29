//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"
#include "DebugToolset.h"


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





/* Create / Reset */

Item ItemBuilder::build() const {
    debug::print("Creating a new item...");
    Item item(keywords, description, actions);
    this->reset();
    return item;
}


void ItemBuilder::reset() const noexcept {
     this->clearAll();
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








/* * *   Private   * * */

void ItemBuilder::clearAll() const {
    this->keywords.clear();
    this->description.clear();
    this->actions.clear();
}


} /* namespace items */
