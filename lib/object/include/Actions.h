//
//  Actions.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Actions
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Actions_h
#define Actions_h

#include "objects.hpp"
#include "ObjectData.h"
#include "Description.h"
#include "Environment.h"


namespace objects {

inline namespace data {


/*!
 @class Action
 
 @brief Stores keyword and description of a single action
 
 @helper Helps constructing object's Actions environment
 */
class Action {
public:
    
    Action(const string &keyword, const string &desc);
    
    Action(const string &keyword, const vector<string> &longdesc);
    
    pair<Key, Description> toPair();
    
private:
    
    Key keyword;
    
    Description description;
    
};










/*!
 @class Actions
 
 @brief All object's action keywords and their descriptions
 
 Environment mapping action's keyword to its description.
 
 If an object in a room has Action("sign", "This is a room..."), then, when
 character types "examine sign", message "This is a room..." will be displayed
 
 @warning Structure may be changed later
 */
class Actions: public ObjectData<Actions> {
public:
    
    Actions();
    
    Actions(const vector<pair<string, string>> &actions);
    
    Actions(vector<Action> &actions);
    
    
    
    
    
    /* ObjectData Protocol */
    
    string toString() const noexcept override;
    
    vector<string> toVector() const noexcept override;
    
    
    
    
    
    /* Environment operations */
    
    /*!
     Add new action to the environment
     @throws std::invalid_argument If action already exists
     */
    void add(Action &&action);
    
    /*! Remove all object's actons */
    void clear();
    
    
    
    
    
    /* Operators */

    Actions& operator=(Actions &other);
    Actions& operator=(const Actions &other);
    
    bool operator==(Actions &other) const;
    bool operator==(const Actions &other) const;
    
private:
    
    /*! Environment that maps all actions */
    Environment<Key, Description> env;
    
};


} /* namespace structures */

} /* namepsace objects */

#endif /* Actions_h */
