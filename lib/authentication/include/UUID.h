//
//  Identifier.h
//  adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Identifier
//
//  Package:             adventure2019
//  Project:             adventure2019
//  Workspace:           Faworki
//  Organization:        maximpuchkov
//  Prefix:              com
//
//  Author:              Maxim Puchkov (mpuchkov@sfu.ca)
//  Full username:       admin
//  Created on:          2019-03-17 at 12:03 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Identifier_h
#define Identifier_h

#include <stdint.h>


namespace identity {
    using id_t = u_int64_t;
}



/**
 @class Identifier
 
 @brief All identifiers are unique
 */
template<typename T>
class UUID {
public:
    
    
    
    /// Generate unique identifier
    T generate();
    
private:
    
    T initial;
    
    T current;
    
};




#endif /* Identifier_h */
