//
//  items.hpp
//  Objects: Item
//  com.maximpuchkov.Objects.Objects.items
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef items_hpp
#define items_hpp

#include "Object.h"
#include "ObjectData.h"

#include "UIText.h"
#include "Environment.h"

#include "print.h" // debug

inline namespace [[deprecated]] defs {
//    using std::string;
    using std::vector;
    using std::pair;
    using std::ostringstream;
    using std::initializer_list;
}


/*! Item scope */
namespace items {

// Keywords, Description, Actions, Attributes data members' typenames
inline namespace data {
    using namespace objects::io;
    using namespace objects::typenames;
    
    using objects::Object;
    
    using ItemIdentifier = objects::ObjectIdentifier;
    using Keyword = std::string;
    using Set = std::set<Keyword>;
    using Vec = std::vector<Keyword>;
} /* namespace data */

} /* namespace items */

#endif /* items_hpp */
