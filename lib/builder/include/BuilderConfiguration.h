//
//  BuilderConfiguration.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.BuilderConfiguration
//
//  Created by mpuchkov on 2019-04-13. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef BuilderConfiguration_h
#define BuilderConfiguration_h

#include "BuilderPrefixHeader.pch"

#include "Object.h"


namespace builders {


/*!
 @class BuilderConfiguration
 
 @brief Determine how to create items.
 
 Builder configuration interface.
 */
class BuilderConfiguration {
public:
    
    /*! Configuration's default constructor and virtual destructor */
    BuilderConfiguration() = default;
    
    virtual ~BuilderConfiguration() = default;
    
    
    
    
    
    /* BuilderConfiguration Interface */

    /*! Reset current object creation */
    virtual void reset() noexcept = 0;
    
    /*! Validate current settings */
    virtual bool validate() const noexcept = 0;
    
};
    

} /* namespace builders */

#endif /* BuilderConfiguration_h */
