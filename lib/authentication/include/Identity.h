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

#include "auth.hpp"


/**
    @class Identity

    @brief < ... >
 */
template<typename Identifier>
class Identity {
public:
    
    /// Initial identifier
    const Identifier initial;
    
    
    /// Identify any type by a assigning a unique identifier
    template<typename T>
    void identify(T &&t);
    
private:
    
    Identifier current;
    
};


#endif /* Identity_h */
