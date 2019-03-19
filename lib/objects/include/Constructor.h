//
//  Constructor.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Constructor_h
#define Constructor_h

#include <vector>
#include <string>

#include "ObjectDataType.h"
#include "Object.h"


using std::string;
using std::vector;

using namespace objects;






/**
 @class Constructor Interface
 
 @brief In-game object interface with a unique object id,
        identifying keywords, and description text.
 */
class Constructor {
public:
    
    /// Reset current object creation
    virtual void reset() = 0;
    
    /// Set object's identifying keywords
    virtual void setKeywords(const KeywordSet &keywords) = 0;
    
    /// Set object's description text
    virtual void setDescription(const Description &description) = 0;
    
};

#endif /* Constructor_h */
