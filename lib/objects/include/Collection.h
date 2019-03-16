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
#include "Object.h"


using std::string;
using std::vector;
using objects::Object;



template<typename T>
class Collection : public Object {
public:
    
    Collection() { }
    
    ObjectID getID() const override;
    
    bool examine(const Keyword &keyword) const override;
    
    string details() const override;
    
    string brief() const override;
    
    
private:
    
    
    std::unordered_set<T> items;
    
};



#endif /* Collection_h */
