//
//  ObjectDataStructure .h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.ObjectDataStructure 
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ObjectDataStructure_h
#define ObjectDataStructure_h

#include "ObjectPrefixHeader.pch"


namespace objects {


/*!
 @struct ObjectDataStructure
 
 @brief Protocol for all object's properties
 
 @templatefield T Typename
 */
template<typename T>
struct ObjectDataStructure {
public:
    
    /*! Convert symbolic data a to viewable string */
    virtual std::string toString() const noexcept = 0;
    
    // Currently not available
    // friend ::std::ostream& operator<<(std::ostream& stream, T data);
    
private:
    
    T& data();
    
};


} /* namespace objects */

#endif /* ObjectDataStructure _h */
