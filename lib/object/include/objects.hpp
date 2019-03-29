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
#include "DebugToolset.h"

using std::string;
using std::vector;
using std::pair;


/*! Object Library scope type definitions */
namespace objects {


/*! Type aliases */
inline namespace typenames {
    using Identifier = uint64_t;
    using Key = string;
    using Text = string;
    using Set = std::set<Key>;
    using Lines = vector<Text>;
} /* namespace typenames */



/*! Forward data structure declarations */
inline namespace structures {
    struct Keywords;
    struct Description;
    struct Actions;
} /* namespace structures */


} /* namespace objects */

#endif /* objects_hpp */
