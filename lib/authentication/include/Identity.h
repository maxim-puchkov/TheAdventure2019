//
//  Identity.h
//  adventure2019: Authentication
//  com.maximpuchkov.Faworki.adventure2019.Identity
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Identity_h
#define Identity_h

namespace auth {
    
inline namespace control {


/**
    @class Identity

    @brief < ... >
 */
template<typename T>
class Identity {
public:
    
    /// Initial identifier
    const T initial;
    
    /// Default constructor
    Identity();
    
    /// Parameterized constructor
    Identity(T initial);
    
    /// 
    T generate_unique_identifier();
    
    /// Identify any type by a assigning a unique identifier
//    template<typename Instance>
//    void identify(Instance &&instance);
    
private:
    
    T current;
    
};


}

}
    
#endif /* Identity_h */
