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
#include <stdint.h>
#include "UUID.h"


using std::string;
using std::vector;



namespace objects {

class Object;

    
using ObjectID = identity::uuid_t;
using Keyword = string;
using Keywords = vector<Keyword>;
using Text = string;
    
    
/* --> */
struct Association;
struct ExtrasBinding;
    
using Extras = vector<objects::Association>;

struct ExtrasBinding {
    Keyword key;
    
};
    
struct Association {
    string key;
    string *values;
};
/* <-- */
  

/**
 @class
    Object Interface
 
 @description
    In-game object interface with a unique object id, identifying keywords, and
    description text.
 */
class Object {
public:
    
    /// Virtual destructor
    virtual ~Object() = 0;
    
    /// Reset current object creation
    virtual void reset() = 0;
    
    /// Set object's identifying keywords
    virtual void setKeywords(const Keywords &keywords) = 0;
    
    /// Set object's description text
    virtual void setDescription(const Text &description) = 0;
    
};
    



}

#endif /* Object_h */
