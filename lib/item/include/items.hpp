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

using std::string;
using std::vector;
using std::pair;
using std::ostringstream;


/*! Item Library scope type definitions */
namespace items {


namespace typenames = objects::typenames;
namespace data = objects::data;


using namespace typenames;
using namespace data;

using objects::Object;
using ItemIdentifier = objects::ObjectIdentifier;


} /* namespace items */


#endif /* items_hpp */
