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

#include "Object.h"

namespace objects {


/*!
 @class Actions
 
 @brief Collection of action keywords and associated examinable descriptions
 */
struct Actions {
public:
    
    Actions();
    
    Actions(const vector<pair<string, string>> &actions);
    
    void clear();
    
    // Actions(Environment<string, string> e);
    
    bool operator==(Actions &other) const;
    bool operator==(const Actions &other) const;
    
private:
    
    
    
    Environment<Key, Description> env;
    
    
};


} /* namepsace objects */

#endif /* Actions_h */
