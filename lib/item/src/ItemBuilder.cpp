//
//  ItemBuilder.cpp
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "ItemBuilder.h"
#include "DebugToolset.h"

using namespace objects;





/* Constructors */

ItemBuilder::ItemBuilder()
: ready(true), keywords(Keywords()), description(Description()), actions(Actions()) {
    debug::PrefixMessage = "ItemBuilder";
}





/* Create / Reset */

Item ItemBuilder::create() {
    Item item(id, keywords, description, actions);
    this->reset();
    
    debug::print("Created item with id = ", id);
    return item;
}


void ItemBuilder::reset() {
     this->clearAll();
}





/* Set Properties */

void ItemBuilder::setKeywords(const vector<string> &keywords) {
    this->keywords = Keywords(keywords);
}


void ItemBuilder::setDescription(const string &text) {
    this->description = Description(text);
}


void ItemBuilder::setActions(const vector<pair<string, string>> &actions) {
    this->actions = Actions(actions);
}











/* * *   Private   * * */

void ItemBuilder::clearAll() {
    this->keywords.clear();
    this->description.clear();
    this->actions.clear();
}
