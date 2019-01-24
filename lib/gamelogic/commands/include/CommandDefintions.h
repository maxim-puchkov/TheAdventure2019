//
//  CommandDefintions.h
//  Commands
//
//  Created by admin on 2019-01-23.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef CommandDefintions_h
#define CommandDefintions_h

#include "Command.h"

template<typename F, typename T>
auto test(const F &fn, T &&params) {
    return [=]{fn(params);};
}

namespace commands {
    using namespace login;
    using namespace user;
    using namespace test;
}

namespace commands::test {
    int cmd() {
        return 1;
    }
    
    template<typename F, typename T>
    auto test(const F &fn, T &&params);
}

#endif /* CommandDefintions_h */
