//
//  Identity.cpp
//  adventure2019: Authentication
//  com.maximpuchkov.Faworki.adventure2019.Identity
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "Identity.h"

using namespace auth;

//using namespace auth::identity;
//
//
//template<typename IdentifierTypename>
//template<class Instance>
//void Identity<IdentifierTypename>::identify(Instance &&instance) {
//    // Validate instance does not have an id
//    
//    // If instance does not have an identifier
//    //   generate new id and assign it
//    
//    // Else, do nothing
//}


template<typename IDType>
Identity<IDType>::Identity()
: initial(0), current(0)
{ }


template<typename IDType>
Identity<IDType>::Identity(IDType initial)
: initial(initial), current(initial)
{ }


template<typename IDType>
IDType Identity<IDType>::generate_unique_identifier() {
    return ++this->current;
}
