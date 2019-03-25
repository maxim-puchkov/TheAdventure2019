//
//  Builder.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Builder_h
#define Builder_h

#include "BuilderLibrary.pch"

using namespace objects;

using std::string;
using std::pair;
using std::vector;


/*!
 @class Builder Interface
 
 @brief Interface for building describable and interactable objects
 */
class Builder {
public:
    
    /* Constructors / Destructor */
    
    Builder();
    
    ~Builder();
    
    
    
    
    
    /* Builder Interface */
    
    /// Reset current object creation
    virtual void reset() noexcept = 0;
    
    /// Set object's identifying keywords
    virtual void setKeywords(const vector<string> &keywords) noexcept = 0;
    
    /// Set object's description text
    virtual void setDescription(const string &description) noexcept = 0;
    
    /// Set object's interactable actions
    virtual void setActions(const vector<pair<string, string>> &actions) noexcept = 0;
    
    /// Each builder maintains list of created objects
    virtual vector<Object *> list() const noexcept = 0;
    
    
    virtual Object::IdentifierTypename requestIdentifier() noexcept = 0;
    
};

#endif /* Builder_h */
