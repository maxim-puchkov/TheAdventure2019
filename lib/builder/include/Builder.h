//
//  Builder.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

#include "BuilderPrefixHeader.pch"

#include "Object.h"


namespace builders {

using std::string;
using std::pair;
using std::vector;
using objects::Object;
using objects::AttributeValue;


/*!
 @class Builder
 
 @brief Interface for building describable and interactable objects
 */
class Builder {
public:
    
    /*! Builder's default constructor and virtual destructor */
    Builder() = default;
    
    virtual ~Builder() = default;
    
    
    
    
    
    /* Builder Interface */
    
    /*! Set object's identifying keywords */
    virtual void setKeywords(const vector<string> &keywords) const noexcept = 0;
    
    /*! Set object's description text */
    virtual void setDescription(const string &description) const noexcept = 0;
    
    /*! Set object's interactable actions */
    virtual void setActions(const vector<pair<string, string>> &actions) const noexcept = 0;
    
    /*! Set equipable object's bonus attributes */
    virtual void setAttributes(initializer_list<AttributeValue> values) const noexcept = 0;
    
    
    
    
    
    /*! Reset current object creation */
    [[deprecated]] virtual void reset() const noexcept = 0;
    
    /*! Validate current settings */
    [[deprecated]] virtual bool validate() const noexcept = 0;
    
};


} /* namespace builders */

#endif /* Builder_h */
