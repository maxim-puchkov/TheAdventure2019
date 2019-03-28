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
#include "Description.h"


namespace objects {


inline namespace structures {


/*!
 @struct Actions
 
 @brief Collection of action keywords and associated examinable descriptions
 
 @warning Incomplete structure
 */
struct Actions {
public:
    
    Actions();
    
    Actions(const vector<pair<string, string>> &actions);
    
    void clear();
    
    // Actions(Environment<string, string> e);
    

    Actions& operator=(Actions &other);
    Actions& operator=(const Actions &other);
    
    bool operator==(Actions &other) const;
    bool operator==(const Actions &other) const;
    
private:
    
    Environment<Key, Description> env;
    
};


} /* namespace structures */


} /* namepsace objects */

#endif /* Actions_h */
