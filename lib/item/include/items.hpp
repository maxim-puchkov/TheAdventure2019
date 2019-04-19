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
#include "print.h"

// #include "ItemData.h"


using std::string;
using std::vector;
using std::pair;
using std::ostringstream;
using std::initializer_list;


// using ItemAttributes = objects::ObjectAttributes;
// using IAValue = uint32_t;
// using ItemAttributeValue =


/*! Item Library scope type definitions */
namespace items {


// Object Interface





// UI Text




    
// Equipment
using ItemIdentifier = objects::ObjectIdentifier;
using AttributeValue = objects::AttributeValue;




// Data class property types
inline namespace data {
    
    using objects::Object;
    using namespace objects::typenames;
    using namespace ui::text;
    
    using Keyword = std::string;
    
    using Set = std::set<Keyword>;
    
    using Vec = std::vector<Keyword>;
    
//
//    using keyword_t = Text;
//    using keywordset_t = std::set<keyword_t>;
//
//    using source_t = std::string;
//
//
//    using KeywordType = keyword_t;
//    using KeywordSetType = keywordset_t;
    //using KeywordType = std::string;
    //using KeywordSetType = std::set<KeywordType>;
    //using Key = std::string;
    //using Set = std::set<Key>;
    //using Text = std::string;
}


// Container storage type
inline namespace container_types {
//
//    // Contain items
//    template<typename SK, class Value>
//    using _TContainer   = Environment<SK, Value>;
//
//    // Contain collections
//    template<typename SK, class Value>
//    using _TContainer2d = Environment<Key, _TContainer<SK, Value> >;
//
//    // Contain containers
//    template<typename SK, class Value>
//    using _TContainer3d = Environment<Key, _TContainer2d<SK, Value> >;
    
} /* namespace container_types */


} /* namespace items */


#endif /* items_hpp */
