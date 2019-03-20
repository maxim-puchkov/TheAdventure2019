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
#include <unordered_set>
#include <functional>
#include <sstream>
#include <iostream>
#include "Item.h"

#include "Constructor.h"
#include "Object.h"

using std::string;



namespace objects {


/**
 @class Collection
 @brief Object that may contain other objects
 
 @discussion WIP
 @ignore
 */
template<typename T>
class Collection : public Object {
public:
    
    Collection() { }
    
    Identifier id() const override;
    
    // KeywordSet& keywords() override;
    
    
    bool examine(const string &keyword) const override;
    
    string brief() const override;
    
    string details() const override;
    
    
private:
    
    std::unordered_set<T> items;
    
};


} /* namespace objects */

#endif /* Collection_h */
