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
#include "Identifiers.h"

using std::string;

class Item {
public:
    
    Item(const string &description);
    
    Item(Item &&item);
    
    virtual ~Item() = 0;
    
    string getDescription();
    
    Item& operator=(Item &&item) noexcept;
    
private:
    
    unsigned long id;
    
    string description;
    
};

#endif /* Item_h */
