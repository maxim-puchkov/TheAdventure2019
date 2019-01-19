//
//  Clothing.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Clothing_h
#define Clothing_h

#include "InteractiveObject.h"

class Clothing : public InteractiveObject {
public:
    
    ~Clothing() { }
    
    bool isWearable() { return true; }
    
private:
    
    Attributes *attributes;
    
};


#endif /* Clothing_h */
