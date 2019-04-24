//
//  auth.hpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.auth
//
//  Created by mpuchkov on 2019-04-04. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef auth_hpp
#define auth_hpp

#include <stdint.h>
#include <utility>
#include <memory>

#include "Authenticator.h"

namespace auth {

inline namespace typenames {
    using Identifier = uint64_t;
    using SharedAuthenticator = const Authenticator<Identifier> *const;
    using SAuth = SharedAuthenticator; // SharedAuthenticator alias type
} /* namespace typenames */


namespace shared {
    constexpr auto authenticator() {
        return std::make_shared<Authenticator<Identifier>>;
    }
    
    constexpr Identifier new_uuid() {
        return 12345; // test id
    }
} /* namespace shared */

} /* namespace auth */

#endif /* auth_hpp */
