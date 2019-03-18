//
//  Identifier.h
//  adventure2019: Authentication
//  com.maximpuchkov.Faworki.adventure2019.Identifier
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef Identifier_h
#define Identifier_h




namespace auth {
    
    
    inline namespace config {
        using IdentifierType = u_int64_t;
    }
    
    
    
    /**
        @class Identity
     
        @brief < ... >
     */
    template<typename IdentifierType = config::IdentifierType>
    class Identity {
    public:
        
        
    
        /// Identify classes by a unique identificator
        template<class Instance>
        void identify(Instance &&instance);
        
    private:
        
        const IdentifierType initial;
        IdentifierType current;
    };
    
    
} /* namespace auth */




// *** *** *** *** *** *** //



template<typename IdentifierType>
template<class Instance>
void auth::Identity<IdentifierType>::identify(Instance &&instance) {
    auto id = instance.getId();
    // ...
}




// *** *** *** *** *** *** //

#endif /* Identifier_h */
