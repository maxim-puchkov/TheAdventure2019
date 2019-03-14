//
//  Item.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include <string>
#include <functional>
#include <iostream>
#include "Object.h"
#include "ItemDescription.h"

using std::string;

using objects::ObjectId;
using objects::Identifiers;
using objects::Extras;


/**
 @class Item
 
 @description
    ...
 */
class Item {
public:
    
    Item(ObjectId id,
         const Identifiers &keywords,
         const ItemDescription &description,
         const Extras &extras); /* undefined */
    
    ObjectId getId() const;
    
private:
    
    ObjectId id;
    ItemDescription description;
    Extras extras;
    
};


template<>
struct std::hash<Item> {
    std::size_t operator()(const Item &item) const;
};







/**
 *  @class Item
 *
 *  @brief Any in-game item
 */

    /*
    Item();
    Item(const string &shortDescription);
    Item(const string &shortDescription, const string &longDescription);
    Item(const Item &item);
    Item(Item &&other);
    virtual ~Item();
    */
    /*
    virtual string getShortDescription() const;
    virtual string getLongDescription() const;
    unsigned long getId() const;
    void setLongDescription(string &&longDescription);
    */
    /*
    virtual Item& operator=(Item &&other) noexcept;
    */
    /*
    bool operator==(Item &other) const;
    bool operator==(const Item &other) const;
    */

/*
template<>
struct std::hash<Item> {
    size_t operator()(const Item &item) const;
};
*/

#endif /* Item_h */
