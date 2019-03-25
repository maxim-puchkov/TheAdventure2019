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

#include "AuthenticationLibrary.pch"


/**
 @namespace auth
 
 @brief Library scope declaration
 */
namespace auth {


inline namespace defaults {
    using Identifier = uint64_t;
}



inline namespace control {

template<typename T = Identifier>
class Identity;

}

}


#endif /* auth_hpp */
