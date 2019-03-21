//
//  ObjectDataType.h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.ObjectDataType
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ObjectDataType_h
#define ObjectDataType_h

#include <string>
#include <unordered_set>
#include <utility>


namespace objects {

namespace data {
    
    inline namespace typenames {
        using Identifier = uint64_t;
        using Key = std::string;
        using Text = std::string;
        using Set = std::unordered_set<Key>;
        using ExtrasBinding = std::pair<std::string, std::string>;
        using Extras = std::vector<ExtrasBinding>;
    } /* namespace typenames */


    inline namespace structures {
        struct KeywordSet;
        struct Description;
        struct CustomActions;
    } /* namespace structures */
    
} /* namespace data */

} /* namespace objects */


#endif /* ObjectDataType_h */
