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
: ready(true),
keywords(Keywords()),
description(Description()),
actions(Actions())
//, authenticator(Authenticator<Object::IdentifierTypename>())
{
    debug::PrefixMessage = "ItemBuilder";
}


ItemBuilder::~ItemBuilder() {
    debug::print("Item builder destroyed.");
}





/* Create / Reset */

Item ItemBuilder::build() const {
    // this->itemID = this->requestIdentifier();
    debug::print("Creating item with id = ", itemID);
    Item item(itemID, keywords, description, actions);
    // this->created.push_back(&item);
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


//vector<Object *> ItemBuilder::list() const noexcept {
//    return this->created;
//}


//Object::IdentifierTypename ItemBuilder::requestIdentifier() noexcept {
//    // return this->authenticator.request_unique_identifier();
//    return 0;
//}








/* * *   Private   * * */

//Object::IdentifierTypename ItemBuilder::identify(Object *object) noexcept {
//    return 0;
//}

void ItemBuilder::clearAll() const {
    this->keywords.clear();
    this->description.clear();
    this->actions.clear();
}


} /* namespace items */
