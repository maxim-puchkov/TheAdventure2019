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

#include "items.hpp"
#include "Description.h"
#include "Environment.h"

namespace items {


typedef Environment<Keyword, Description> Interactions;


/*!
 @class Action
 
 @brief Stores keyword and description of a single action
 
 @helper Helps constructing object's Actions environment
 */
class Action {
public:
    
    Action(const Keyword &keyword, const string &desc);
    Action(const Keyword &keyword, const vector<string> &longdesc);
    
    std::pair<Keyword, Description> toPair() const;
    
private:

    Keyword keyword;
    
    Description description{"No description"};
    
};










/*!
 @class Actions
 
 @brief All object's action keywords and their descriptions
 
 Environment mapping action's keyword to its description.
 
 If an object in a room has Action("sign", "This is a room..."), then, when
 character types "examine sign", message "This is a room..." will be displayed
 
 @warning Structure may be changed later
 */
class Actions: public objects::ObjectData<Actions> {
public:

    Actions() = default;
    
    Actions(const Actions &actions) = default;
    
    Actions(const vector<pair<string, string>> &actions);
    
    Actions(const vector<Action> &actions);
    
    
    
    
    
    /* ObjectData Protocol */
    
    string toString() const noexcept override;
    
    vector<string> toVector() const noexcept override;
    
    
    
    
    
    /* Operations and states */
    
    /*!
     Add new action to the environment
     @throws std::invalid_argument Exception is thrown if action already exists
     */
    void add(const Action &action);

    bool empty() const;
    
    bool isInteractable() const noexcept;
    
    size_type size() const noexcept override;
    
    /*! Remove all object's actions */
    void clear() noexcept override;
    
    
    /* Operators */

//    Actions& operator=(Actions &&other) noexcept;
//    Actions& operator=(const Actions &other) noexcept;
    
    bool operator==(Actions &&other) const noexcept;
    bool operator==(const Actions &other) const noexcept;
    
private:
    
    /*! Keywords that can be interacted with */
    Interactions env;
    
};


} /* namepsace items */

#endif /* Actions_h */
