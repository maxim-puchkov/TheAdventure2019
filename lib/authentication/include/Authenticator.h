//
//  Authentication.h
//  Authentication
//  com.maximpuchkov.Faworki.adventure2019.Authentication
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Authentication_h
#define Authentication_h

namespace auth {


/*!
 @class Authenticator
 
 @brief Generates universally unique identifiers
 
 Identifiers are generated incrementaly.
 */
template<typename T>
class Authenticator {
public:
    
    /*! Authenticator parent's (initial) identifier */
    constexpr T parent_id() { return 0; }
    // const T parent_id = 0;
    
    /*! Request new unique identifier from this authenticator instance */
    T requestUniqueIdentifier() const noexcept {
        return ++this->current;
    }
    
    /*! Alias function of requestUniqueIdentifier */
    T uuid() const noexcept {
        return this->requestUniqueIdentifier();
    }
    
private:
    
    mutable T current = 0;

};


} /* namespace auth */

#endif /* Authentication_h */
