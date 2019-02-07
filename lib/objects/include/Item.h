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

using std::string;
using std::size_t;

class Item {
public:
    
    Item() { }
    
    Item(const string &description);
    
    Item(Item &&item);
    
    virtual ~Item() { };
    
    unsigned long getId() const;
    
    string getDescription();
    
    Item& operator=(Item &&other) noexcept;
    
    bool operator==(Item &other) const;
    
    bool operator==(const Item &other) const;

    
private:
    
    unsigned long id;
    
    string description;
    
};

template <> struct std::hash<Item> {
    size_t operator()(const Item& item) const;
};

#endif /* Item_h */
