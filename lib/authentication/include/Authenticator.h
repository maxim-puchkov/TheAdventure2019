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


namespace auth {


/*!
 @class Authenticator
 
 @brief Generate unique identifiers.
 */
template<typename T>
class Authenticator {
public:
    
    /*! Authenticator parent's identificator (initial id) */
    const T parent_id = 0;
    
    /*! Identifiers are generated incrementaly */
    T requestUniqueIdentifier() const noexcept {
        (const_cast<Authenticator *>(this))->current++;
        return this->current;
    }
    
    /*! Alias function */
    T uuid() const noexcept {
        return this->requestUniqueIdentifier();
    }
    
    
    /* */
    Authenticator() { }
//    : Authenticator(0)
//    { }
    
//    Authenticator(T initial)
//    : parent_id(initial), current(initial)
//    { }
//    
private:
    
    T current = 0;

};


}

#endif /* Authentication_h */
