//
//  objects.hpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.objects
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef objects_hpp
#define objects_hpp

#include "ObjectPrefixHeader.pch"
#include "ui.hpp"

/*! Object Library scope type definitions */
namespace objects {
inline namespace typenames {
    
    typedef std::size_t size_type;
    
    using namespace ui::text;
    
    using ObjectIdentifier = uint64_t;
    using AttributeValue = int32_t;
    
    
//    inline namespace streams {
//
//        using data_ostream = std::ostringstream;
//        using data_ostream_iterator = std::ostream_iterator<std::string>;
//
//        using data_istream = std::istringstream;
//        using data_istream_iterator = std::istream_iterator<std::string>;
//
//    } /* namespace data */
    
    
} /* namespace typenames */
} /* namespace objects */

#endif /* objects_hpp */
