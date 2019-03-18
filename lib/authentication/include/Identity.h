//
//  Identity.h
//  adventure2019: Authentication
//  com.maximpuchkov.Faworki.adventure2019.Identity
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Identity_h
#define Identity_h

#include "Auth.h"
using namespace auth;



namespace auth::identity {


/**
 @class Identity
 
 @brief < ... >
 */
template<typename IdentifierType> // = config::IdentifierType>
class Identity {
public:
    
    /// Identify any instance by a unique identificator number
    template<class Instance>
    void identify(Instance &&instance);
    
private:
    
    const IdentifierType initial;
    IdentifierType current;
};
    
    
}

#endif /* Identity_h */
