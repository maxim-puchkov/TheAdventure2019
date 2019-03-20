//
//  auth.hpp
//  adventure2019: Authentication
//  com.maximpuchkov.Faworki.adventure2019.Auth
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Auth_h
#define Auth_h

#include <stdint.h>
#include "Identity.h"


/**
 @namespace auth
 
 @brief Library scope declaration
 */
namespace auth {

/// Unsigned integer number
inline namespace defaults {
    using IdentifierTypename = uint64_t;
}



///
class Authentication;

///
template<typename T = IdentifierTypename>
class Identity;
    
}


#endif /* auth_hpp */
