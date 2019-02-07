//
//  Collection.h
//  adventure2019
//
//  Created by admin on 2019-02-06.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Collection_h
#define Collection_h

#include <string>
#include <functional>
#include <unordered_set>
#include "Item.h"

using std::unordered_set;
using std::string;

const unsigned int NO_LIMIT = 0;

class Collection : public Item {
public:
    
    Collection(const string &description) : Item(description) { }
    
    Collection(Item &&c) : Item(std::move(c)) { }
    
    ~Collection() { }
    
    void setLimit(unsigned int limit) {
        if (limit > this->limit) throw(std::invalid_argument("Collection limit"));
        this->limit = limit;
    }
    
    bool add(Item &&item) {
        if (!this->full()) {
            return (this->items.insert(std::move(item))).second;
        }
        return false;
    }
    
    bool remove(Item &&item) {
        return (this->items.erase(std::move(item)) == 1);
    }
    
private:
    
    unordered_set<Item> items;
    
    unsigned int limit = NO_LIMIT;
    
    bool limited() {
        return this->limit != NO_LIMIT;
    }
    
    bool full() {
        if (!this->limited()) {
            return false;
        }
        return this->items.size() == this->limit;
    }
    
};

#endif /* Collection_h */
