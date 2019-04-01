//
//  ObjectData .h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.ObjectData 
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ObjectData_h
#define ObjectData_h

#include "objects.hpp"


namespace objects {


/*!
 @class ObjectData
 
 @brief Convert object's properties
 
 Protocol for all object's properties. Keywords, Description
 and Actions can be converted and serialized.
 */
template<class T>
class ObjectData {
public:
    
    /*! Convert symbolic data a to viewable string */
    virtual string toString() const noexcept = 0;

    /*! Convert symbolic data to a vector of strings */
    virtual vector<string> toVector() const noexcept = 0;
    
     
     
    // Currently not available
    /* Write directly to output stream */
    // friend ::std::ostream& operator<<(std::ostream& stream, T data);
    
private:
    
    T& data() {
        return *static_cast<T*>(this);
    }
    
};


} /* namespace objects */

// Ambiguous
//template<class T>
//std::ostream& operator<<(std::ostream &stream, T structure) {
//    stream << objects::ObjectData<T>::data().toString();
//    return stream;
//}

#endif /* ObjectData _h */
