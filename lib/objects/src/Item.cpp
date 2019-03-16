//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include <set>
#include "Item.h"


Item::Item(ObjectID id,
           const std::set<Keyword> &keywords,
           const ItemDescription &description,
           const Extras &extras)
: id(id), keywords(keywords), description(description), extras(extras)
{
   // std::set<Keyword> keywords = (keywords)
    
}


ObjectID Item::getID() const {
    return this->id;
}


string Item::display() const {
    //return this->keywords[0];
    return "";
}


string Item::display_long() const {
    return "";
}



bool Item::hasKeyword(const Keyword &keyword) const {
    return this->keywords.find(keyword) != this->keywords.end();
}


bool Item::examine(const Keyword &keyword) const {
    return true;
}


string Item::display_keywords() const {
    // output = "";
//    const char *SEPARATOR = ", ";
//    for (auto &k : this->keywords) {
//        output
//    }
    
    // Keywords: [set, s, e, KEY, set]
    
//    stringstream ss(input); 
//return {istream_iterator<string>{ss},  
//        istream_iterator<string>{}};
//    std::ostringstream oss(this->keywords);
//
//    std::stringstream x("");
    
    //std::{istream_iterator<string>{ss},          istream_iterator<string>{}};
    
    return "";
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
