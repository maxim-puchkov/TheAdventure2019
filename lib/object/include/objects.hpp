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

/*! Object Interface scope */
namespace objects {
    
namespace io {
    using namespace ui::text;
} /* namespace io */


inline namespace typenames {
    using namespace ui::text;
    
    typedef std::size_t size_type;
    
    using ObjectIdentifier = uint64_t;
    using AttributeValue = int32_t;    
} /* namespace typenames */

} /* namespace objects */

#endif /* objects_hpp */
