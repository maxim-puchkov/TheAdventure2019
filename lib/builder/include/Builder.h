//
//  Builder.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

// #include <string>
// #include <vector>

// #include "ObjectDataType.h"
// #include "Object.h"


// using std::string;
// using std::vector;

// using namespace objects;






/**
 @class Builder Interface
 
 @brief In-game object interface with a unique object id,
        identifying keywords, and description text.
 */
class Builder {
public:
    
    /// Reset current object creation
    virtual void reset() = 0;
    
    /// Set object's identifying keywords
    virtual void setKeywords(const KeywordSet &keywords) = 0;
    
    /// Set object's description text
    virtual void setDescription(const Description &description) = 0;
    
    
    // template<typename KeywordSet>
    // virtual void setKeywords(const KeywordSet &keywords) = 0;
    
    // template<typename Description>
    // virtual void setDescription(const Description &description) = 0;
    
};

#endif /* Builder_h */
