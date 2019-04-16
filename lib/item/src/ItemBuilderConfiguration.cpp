//
//  ItemBuilderConfiguration.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ItemBuilderConfiguration
//
//  Created by mpuchkov on 2019-04-15. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "ItemBuilderConfiguration.h"



namespace items {
    void ItemBuilderConfiguration::reset() noexcept {
        this->keywords = Keywords::DEFAULT_INSTANCE;
        
        this->description = Description::DEFAULT_INSTANCE;
        this->actions = Actions::DEFAULT_INSTANCE;
        this->attributes = ItemAttributes::DEFAULT_INSTANCE;
    }
}


/* namespace items */
