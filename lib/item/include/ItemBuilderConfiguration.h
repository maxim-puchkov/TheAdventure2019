//
//  ItemBuilderConfiguration.h
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ItemBuilderConfiguration
//
//  Created by mpuchkov on 2019-04-13. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ItemBuilderConfiguration_h
#define ItemBuilderConfiguration_h

#include "items.hpp"
#include "ItemData.h"
#include "Builder.h"
#include "BuilderConfiguration.h"

namespace items {
    

///* Default property values */
//inline namespace item_builder_defaults {
//
//    const Keywords NO_KEYS{};
//
//    const Description DEF_DESC{"No description"};
//    const Actions DEF_ACTS{{}};
//    const ItemAttributes DEF_ATTR{0, 0};
//
//}




/*! @class ItemBuilderConfiguration */
class ItemBuilderConfiguration: public builders::BuilderConfiguration {
public:
    
    /* Configuration constructor */
    ItemBuilderConfiguration();
    ~ItemBuilderConfiguration() = default;
    
    
    
    /* BuilderConfiguration protocol */
    bool validate() const noexcept override;
    void reset() noexcept override;
    
    
    
    /* Item's properties */
    mutable Keywords keywords;
    
    mutable Description description;
    mutable Actions actions;
    mutable ItemAttributes attributes;
    
};




ItemBuilderConfiguration::ItemBuilderConfiguration() {
    this->reset();
}
    
bool ItemBuilderConfiguration::validate() const noexcept {
    return (!this->keywords.empty());
}




} /* namespace items */

#endif /* ItemBuilderConfiguration_h */
