//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"

namespace items {


/* Constructors */

Item::Item(ItemIdentifier id,
           const Keywords &keywords,
           const Description &description,
           const Actions &actions)
    : Item(id, 0, keywords, description, actions)
{ }


Item::Item(ItemIdentifier id,
           int json_id,
           const Keywords &keywords,
           const Description &description,
           const Actions &actions)
    : id(id),
    json_id(json_id),
    keywords(keywords),
    description(description),
    actions(actions)
{ }


//Item::Item(Item &&other) noexcept
//    : id(std::move(other.id)),
//    json_id(std::move(other.json_id)),
//    keywords(std::move(other.keywords)),
//    description(std::move(other.description)),
//    actions(std::move(other.actions)),
//    attributes(std::move(other.attributes))
//{ }

    


/* Object Interface */

ItemIdentifier Item::identifier() const {
    return this->id;
}


Text Item::info() const {
    return this->description.brief();
}


Text Item::details() const {
    return this->description.full();
}


Text Item::toText() const {
    OStream stream;
    auto DEL = ui::text::styles::CS;
    
    stream << "Item (";
    stream << "id: " << this->id << DEL;
    stream << "keywords: {" << this->keywords.toString() << "}" << DEL;
    stream << "description: \"" << this->description.toString() << "\"" << DEL;
    stream << "actions: {" << this->actions.toString() << "}";
    stream << ")";
    
    return stream.str();
}


Text Item::examine(const Text &keyword) const {
    // .....
    
    return "callee: Item::examine(const Text&)";
}


bool Item::isInteractable() const {
    return this->actions.isInteractable();
}

bool Item::isEquipable() const {
    return false;
    // return this->attributes.isEquipable();
}





/* Operators */

//Item& Item::operator=(Item &&other) noexcept {
//    this->keywords = std::move(other.keywords);
//    this->description = std::move(other.description);
//    this->actions = std::move(other.actions);
//    this->attributes = std::move(other.attributes);
//
//    return *this;
//}
//
//Item& Item::operator=(const Item &other) noexcept {
//    this->keywords = other.keywords;
//    this->description = other.description;
//    this->actions = other.actions;
//    this->attributes = other.attributes;
//
//    return *this;
//}


bool Item::operator==(Item &&other) const noexcept {
    return (this->id == other.id);
}

bool Item::operator==(const Item &other) const noexcept {
    return (this->id == other.id);
}


bool Item::operator!=(Item &&other) const noexcept {
    return (this->id != other.id);
}

bool Item::operator!=(const Item &other) const noexcept {
    return (this->id != other.id);
}


} /* namespace items */




namespace std {


size_t hash<Item>::operator()(const Item &item) const {
    return hash<items::ItemIdentifier>{}(item.identifier());
}


} /* namespace std */
