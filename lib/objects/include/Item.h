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
#include "Identifiers.h"
#include <iostream>

using std::string;
using std::size_t;


/**
 *  @class Item
 *
 *  @brief Any in-game item
 */
class Item {
public:
    
    Item();
    
    Item(const string &shortDescription);
    
    Item(const string &shortDescription, const string &longDescription);
    
    Item(const Item &item);
    
    Item(Item &&other);
    
    virtual ~Item();
    
    
    
    
    
    virtual string getShortDescription() const;
    
    virtual string getLongDescription() const;
    
    unsigned long getId() const;
    
    void setLongDescription(string &&longDescription);
    
    
    
    
    
    virtual Item& operator=(Item &&other) noexcept;
    
    bool operator==(Item &other) const;
    
    bool operator==(const Item &other) const;
    
private:
    
    string shortDescription;
    
    string longDescription;
    
    unsigned long id;
    
};


template<>
struct std::hash<Item> {
    size_t operator()(const Item &item) const;
};


#endif /* Item_h */
