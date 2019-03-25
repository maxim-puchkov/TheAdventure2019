//
//  Authentication.cpp
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
//  Created on:          2019-03-16 at 4:38 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "Authenticator.h"

namespace auth {

template<typename IdentifierTypename>
Authenticator<IdentifierTypename>::Authenticator()
: identity(Identity<Identifier>())
{ }


template<typename IdentifierTypename>
IdentifierTypename Authenticator<IdentifierTypename>::request_unique_identifier() noexcept {
    return this->identity.generate_unique_identifier();
}

    template<typename IdentifierTypename>
    Authenticator<IdentifierTypename>& Authenticator<IdentifierTypename>::operator=(Authenticator &&other) {
        this->identity = std::move(other.identity);
        return *this;
    }

} /* namespace auth */
