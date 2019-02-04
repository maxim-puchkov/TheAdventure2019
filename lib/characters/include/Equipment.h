//
//  Equipment.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Equipment_h
#define Equipment_h

#include "Clothing.h"

class Equipment {
public:
    
    Equipment() {
        // this->hat = Clothing();
    }
    
    virtual ~Equipment() { }
    
    virtual Attributes attributeBonus() const {
        return this->hat.getAttributes();
    }
    
private:
    
    Clothing hat;
    
};

#endif /* Equipment_h */
