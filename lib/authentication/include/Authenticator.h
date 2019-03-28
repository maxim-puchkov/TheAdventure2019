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

#include "auth.hpp"


namespace auth {
//inline namespace control {

template<typename T>
class Authenticator {
public:
    
    /// Initial identifier
    const T initial;
    
    /// Default constructor
    Authenticator();
    
    /// Parameterized constructor
    Authenticator(T initial);
    
    ///
    T generate_unique_identifier();
    
    /// Identify any type by a assigning a unique identifier
    //    template<typename Instance>
    //    void identify(Instance &&instance);
    
private:
    
    T current;

};

//}
}

#endif /* Authentication_h */
