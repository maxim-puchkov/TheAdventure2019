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

namespace objects {
    
    inline namespace typenames {
        using Identifier = uint64_t;
        using Key = std::string;
        using Text = std::string;
        using Set = std::set<Key>;
        
        // temp
        using ExtrasBinding = std::pair<std::string, std::string>;
        using Extras = std::vector<ExtrasBinding>;
    } /* namespace typenames */

    struct KeywordSet;
    struct Description;
    struct CustomActions;

} /* namespace objects */

#endif /* objects_hpp */
