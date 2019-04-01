//
//  convertable.h
//  Objects: Objects
//  com.maximpuchkov.Objects.Objects.convertable
//
//  Created by mpuchkov on 2019-03-30. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef convertable_h
#define convertable_h


template<typename T>
class __convertable {
private:
    
    typedef char to_s_valid[0];
    typedef char to_s_invalid[1];
    template<typename C> static to_s_valid& to_s_validate(decltype(&C::toString));
    template<typename C> static to_s_invalid& to_s_validate(...);


    typedef char to_v_valid[0];
    typedef char to_v_invalid[1];
    template<typename C> static to_v_valid& to_v_validate(decltype(&C::toVector));
    template<typename C> static to_v_invalid& to_v_validate(...);
    
public:
    
    enum {
        to_string = sizeof(to_s_validate<T>(0)) == sizeof(to_s_valid),
        to_string_vector = sizeof(to_v_validate<T>(0)) == sizeof(to_v_valid)
    };
    
};


#endif /* convertable_h */
