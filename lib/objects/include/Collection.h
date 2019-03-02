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
    
    Collection(const string &description);
    
    Collection(Collection &&c);
    
    ~Collection();
    
    
    
    
    
    /* Retrieve */
    
    unordered_set<Item> getItems() const;
    
    string getShortDescription() const override;
    
    string getLongDescription() const override;
    
    
    
    
    
    
    /* Modify */
    
    void setLimit(unsigned int limit);
    
    bool add(Item &&item);
    
    bool remove(Item &&item);
    
    Collection& operator=(Collection &&c) noexcept;
    
private:
    
    string shortDescription;
    
    string longDescription;
    
    unordered_set<Item> items;
    
    unsigned int limit = NO_LIMIT;
    
    bool isLimited();
    
    bool isFull();
    
};

#endif /* Collection_h */
