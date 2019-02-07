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
    
    Item(const string &description);
    
    Item(const Item &item);
    
    Item(Item &&item);
    
    virtual ~Item() { };
    
    virtual string getDescription() const;
    
    
    
    
    
    virtual Item& operator=(Item &&other) noexcept;
    
    bool operator==(Item &other) const;
    
    bool operator==(const Item &other) const;
    
    unsigned long getId() const;

    
private:
    
    string description;
    
    unsigned long id;
    
};

template<>
struct std::hash<Item> {
    size_t operator()(const Item& item) const;
};

#endif /* Item_h */
