//
//  UUID.h
//  Constructors
//
//  Created by admin on 2019-03-14.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef UUID_h
#define UUID_h

#include <stdint.h>




namespace identity {

using uuid_t = u_int64_t;



/**
 @struct
    UUID
 
 @description
    Generates universally unique identifiers
 */
class UUID {
public:
    
    /// Default non-parameterized constructor
    UUID();
    
    
    /// Overwrite the initial identifier value
    UUID(uuid_t init);
    
    
    /// Generate universally unique identifier
    uuid_t generate();
    
    
    /// Reset identifiers to initial value
    void reset();
    
    
private:
    
    const uuid_t INIT;
    
    uuid_t previousID;
    
};


}
#endif /* UUID_h */
