//
//  UUID.cpp
//  Objects
//
//  Created by admin on 2019-03-14.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#include "UUID.h"


namespace identity {


/// Default initial value
const u_int64_t DEF_INIT = 0;

    
// Definitions
const uuid_t INIT = 0;
uuid_t previousID = INIT;


    
    
UUID::UUID()
: INIT(DEF_INIT)
{ }
    

UUID::UUID(uuid_t init)
: INIT(init)
{ }


uuid_t UUID::generate() {
    return ++this->previousID;
}


void UUID::reset() {
    this->previousID = INIT;
}


}
