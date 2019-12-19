//
//  Authentication.h
//  Authentication
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Authentication_h
#define Authentication_h


#include <stdint.h>
#include <utility>


inline namespace {
    using Identifier = uint64_t;
}


namespace auth {

/*!
 @class Authenticator
 
 @brief Generate unique identifiers.
 
 If only one Authenticator is used, all generated identifiers will
 be universally unique. Class was initially designed to identify
 all of: characters, rooms, and objects.
 */
template<typename T>
class Authenticator {
public:
    
    /*! Authenticator parent's identificator (initial id) */
    const T parent_id;
    
    /* */
    Authenticator()
    : Authenticator(0)
    { }
    Authenticator(T initial)
    : parent_id(initial), current(initial)
    { }
    
    
    /*! Identifiers are generated incrementaly */
    T generateUniqueIdentifier() const {
        return ++this->current;
    }
    
private:
    
    mutable T current;

};


} /* namespace auth */

#endif /* Authentication_h */
