//
//  ItemConstructor.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ItemConstructor_h
#define ItemConstructor_h

#include <vector>
#include <string>
#include "Object.h"
#include "Item.h"
#include "ItemDescription.h"

using std::string;
using std::vector;
using objects::ObjectId;
using objects::Identifiers;
using objects::Text;
using objects::Association;

const unsigned int LINE_WIDTH = 80;
const unsigned int SHORT_DESCRIPTION_WIDTH = 20;


/**
 @class
    ItemConstructor
 
 @description
    Constructs items with keywords and short/long descriptions.
 */
class ItemConstructor : public objects::Object {
public:
    
    ItemConstructor();
    
    Item create();
    
    void setIdentifiers(Identifiers identifiers) override {
        this->keywords = identifiers;
    }
    
    void setDescription(Text description) override {
        //this->description = ItemDescription(description, LINE_WIDTH, SHORT_DESCRIPTION_WIDTH);
    }
    
private:
    
    Identifiers keywords;
    ItemDescription description;
    Extras extras; // additional actions of an item
    
};

#endif /* ItemConstructor_h */
