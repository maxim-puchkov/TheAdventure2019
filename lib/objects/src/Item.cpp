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


string Item::brief() const {
    //return this->keywords.first();
    return *this->keywords.cbegin();
}


string Item::details() const {
    
    return this->allKeywords();
}



bool Item::examine(const Keyword &keyword) const {
    
    return true;
}


string Item::allKeywords() const {
    const string delim = ", ";
    return this->allKeywords(delim);
}

string Item::allKeywords(const string &delimeter) const {
    std::ostringstream oss;
    for (auto &k : this->keywords) {
        oss << k << delimeter;
    }
    return oss.str();
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
