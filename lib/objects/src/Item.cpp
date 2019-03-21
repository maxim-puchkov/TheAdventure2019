//
//  Item.cpp
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//


#include <set>
#include "Item.h"

using namespace objects;


//Item::Item(Identifier id,
//           const KeywordSet &keywords,
//           const Description &description,
//           const Extras &extras)
//: itemID(id), keywords(keywords), description(description), extras(extras)
//{ }


Identifier Item::id() const {
    // return this->itemID;
    throw 2;
}


string Item::brief() const {
    return this->keywords.first();
}


string Item::details() const {
    return this->keywords.asString();
}


bool Item::hasKeyword(const Key &keyword) const {
    return this->keywords.contains(keyword);
}


bool Item::examine(const Key &keyword) const {
    
    // .....
    return true;
    
}


//std::size_t std::hash<Item>::operator()(const Item &item) const {
//    return std::hash<unsigned long>{}(item.getID());
//}


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
