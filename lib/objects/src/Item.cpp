//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "Item.h"

ObjectID Item::getID() const {
    return this->id;
}


std::size_t std::hash<Item>::operator()(const Item &item) const {
    return std::hash<unsigned long>{}(item.getID());
}


/*
{
    "id": 1102,
 
    "keywords": [ "sign" ],
 
    "shortdesc": "a sign",
 
    "longdesc": [ "A sign demands your attention." ],
 
    "extra": [ {
        "keywords": [ "sign" ],
 
        "desc": [
            "Welcome to the Shire.  As you enter the Shire from Haon-Dor you come under",
            "the jurisdiction of the Thain, the peacekeeper of the Shire.  Consequently,",
            "by entering these lands you agree to obey our laws.  If you break these laws,",
            "you will be severely punished.  We do not like riff raff in our peaceful",
            "town.",
            "",
            "\t\t\t\t\tThe Thain",
            "\t\t\t\t\tPeacekeeper of the Shire",
            ""
          ]
        }
    ]
}
 */



/*
 
#include <iostream>
 
 
Item::Item() { }


Item::Item(const string &shortDescription)
: shortDescription(shortDescription), longDescription(shortDescription) { }


Item::Item(const string &shortDescription, const string &longDescription)
: shortDescription(shortDescription), longDescription(shortDescription) {
    //Item();
}


Item::Item(const Item &other)
: shortDescription(std::move(other.shortDescription)),
longDescription(std::move(other.longDescription)) {
    this->id = other.id;
}


Item::Item(Item &&other)
: shortDescription(std::move(other.shortDescription)),
longDescription(std::move(other.longDescription)) {
    this->id = other.id;
}


Item::~Item()
{ }


unsigned long Item::getID() const {
    return this->id;
}


string Item::getShortDescription() const {
    return this->shortDescription;
}


string Item::getLongDescription() const {
    return this->longDescription;
}


void Item::setLongDescription(string &&longDescription) {
    this->longDescription = std::move(longDescription);
}


Item& Item::operator=(Item &&other) noexcept {
    this->id = std::move(other.id);
    this->shortDescription = std::move(other.shortDescription);
    return *this;
}


bool Item::operator==(Item &other) const {
    return this->id == other.id;
}


bool Item::operator==(const Item &other) const {
    return this->id == other.id;
}


size_t std::hash<Item>::operator()(const Item &item) const {
    return std::hash<unsigned long>{}(item.getID());
}
*/
