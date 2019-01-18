//
//  Item.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Item_h
#define Item_h

#include "InteractiveObject.h"

class Item : public InteractiveObject {
public:
    
    bool isWearable() { return false; }

private:
    
};


#endif /* Item_h */
