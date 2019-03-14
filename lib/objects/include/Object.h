//
//  Object.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include <vector>
#include <string>

using std::string;
using std::vector;


namespace objects {

struct Association;
class Object;

using Identifier = string;
using Identifiers = vector<Identifier>;
using Text = string;
using ObjectId = unsigned long;
using Extras = vector<objects::Association>;


    
    
    
    
struct Association {
    string key;
    string *values;
};
  

/**
 @class Object
 
 @description
    In-game object with a unique object id, identifying names, and
    description text. Ensures that an object has exactly one object id.
 */
class Object {
public:
    
    virtual void setIdentifiers(Identifiers identifiers) = 0;
    
    virtual void setDescription(Text description) = 0;
    
protected:
    
    ObjectId uniqueId();
    
};
    



}

#endif /* Object_h */
