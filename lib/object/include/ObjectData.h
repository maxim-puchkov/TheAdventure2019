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
 
 Keywords, Description, Actions, and Attributes are can be converted and serialized.
 */
template<class DataType>
class ObjectData {
public:
    
    /*! Size of a data class's underlying collection */
    virtual std::size_t size() const noexcept = 0;
    
    /*! Clear all properties of a data class */
    virtual void clear() noexcept = 0;
    
    
    
    /* Convert */
    
    /*! Convert symbolic data to a displayable string */
    virtual std::string toString() const noexcept = 0;

    /*! Convert symbolic data to a displayable vector of strings */
    virtual std::vector<std::string> toVector() const noexcept = 0;
    
private:
    
    /*! Clear all properties and restore initial values */
    // virtual DataType default_data_instance() const noexcept = 0;

    /*! Generate default object of this class */
    // virtual DataType default_object() const noexcept = 0;
    
    
    
    /*! @ignore */
    DataType& data();
    
};



template<class DataType>
DataType& ObjectData<DataType>::data() {
    return *(static_cast<DataType *>(this));
}


} /* namespace objects */

#endif /* ObjectData _h */
