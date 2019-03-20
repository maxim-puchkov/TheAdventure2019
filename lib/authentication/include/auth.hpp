//
//  Auth.h
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


namespace auth {

/// Default id type
using IdentifierTypename = uint64_t;



///
class Authentication;

///
template<typename T = IdentifierTypename>
class Identity;
    

}


#endif /* Auth_h */
