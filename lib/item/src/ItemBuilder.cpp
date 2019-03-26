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
using auth::Authenticator;




/* Constructors */

ItemBuilder::ItemBuilder()
: ready(true),
keywords(Keywords()),
description(Description()),
actions(Actions())
//, authenticator(Authenticator<Object::IdentifierTypename>())
{
    debug::PrefixMessage = "ItemBuilder";
}





/* Create / Reset */

Item ItemBuilder::create() {
    debug::print("Creating item with id = ", id);
    Item item(id, keywords, description, actions);
    this->created.push_back(&item);
    this->reset();
    return item;
}


void ItemBuilder::reset() noexcept {
     this->clearAll();
}





/* Set Properties */

void ItemBuilder::setKeywords(const vector<string> &keywords) noexcept {
    this->keywords = Keywords(keywords);
}


void ItemBuilder::setDescription(const string &text) noexcept {
    this->description = Description(text);
}


void ItemBuilder::setActions(const vector<pair<string, string>> &actions) noexcept {
    this->actions = Actions(actions);
}


vector<Object *> ItemBuilder::list() const noexcept {
    return this->created;
}


Object::IdentifierTypename ItemBuilder::requestIdentifier() noexcept {
    //return this->authenticator.request_unique_identifier();
    return 0;
}








/* * *   Private   * * */

void ItemBuilder::clearAll() {
    this->keywords.clear();
    this->description.clear();
    this->actions.clear();
}
