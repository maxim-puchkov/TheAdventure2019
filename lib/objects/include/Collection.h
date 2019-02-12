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
#include <sstream>
#include <iostream>
#include "Item.h"

using std::unordered_set;
using std::string;

const unsigned int NO_LIMIT = 0;


/**
 *  @class Collection
 *
 *  @brief Collection of items.
 *
 *  Collection of items (bag, chest) is also an item.
 */
class Collection : public Item {
public:
    
    Collection(const string &description) : shortDescription(description) { }
    
    Collection(Collection &&c) : shortDescription(std::move(c.shortDescription)), items(std::move(c.items)) { }
    
    ~Collection() { }
    
    
    
    
    
    /* Retrieve */
    
    unordered_set<Item> getItems() const {
        return this->items;
    }
    
    string getShortDescription() const override;
    
    string getLongDescription() const override;
    
    
    
    
    
    
    /* Modify */
    
    void setLimit(unsigned int limit) {
        this->limit = limit;
    }
    
    bool add(Item &&item) {
        return (!this->full() && (this->items.insert(std::move(item))).second);
    }
    
    bool remove(Item &&item) {
        return (this->items.erase(std::move(item)) == 1);
    }
    
    
    
    
    
    
    Collection& operator=(Collection &&c) noexcept {
        this->items = std::move(c.items);
        return *this;
    }
    
private:
    
    string shortDescription;
    
    string longDescription;
    
    unordered_set<Item> items;
    
    unsigned int limit = NO_LIMIT;
    
    bool limited() {
        return (this->limit != NO_LIMIT);
    }
    
    bool full() {
        return (this->limited() && (this->items.size() == this->limit));
    }
    
};

#endif /* Collection_h */
