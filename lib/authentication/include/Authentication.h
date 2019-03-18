//
//  Authentication.h
//  Authentication
//  com.maximpuchkov.Faworki.adventure2019.Authentication
//
//  Package:             Authentication
//  Project:             adventure2019
//  Workspace:           Faworki
//  Organization:        maximpuchkov
//  Prefix:              com
//
//  Author:              Maxim Puchkov (mpuchkov@sfu.ca)
//  Full username:       admin
//  Created on:          2019-03-16 at 4:37 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Authentication_h
#define Authentication_h


#include <stdint.h>

#include "Auth.h"
#include "Identity.h"



namespace auth {
    
    inline namespace config {
        using IdentifierType = u_int64_t;
    }
    
    class Authentication {
    public:
        IdentifierType newIdentifier() const;
    private:
    };
    
    namespace identity {
        Identity<config::IdentifierType> identifiers();
    }
    
}

#endif /* Authentication_h */
