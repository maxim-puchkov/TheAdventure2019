//
//  InteractiveObject.h
//  test
//
//  Created by admin on 2019-01-17.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef InteractiveObject_h
#define InteractiveObject_h

#include <string>

class InteractiveObject {
public:
    
    virtual ~InteractiveObject() { }
    
    virtual bool isWearable() = 0;
    
    virtual void put() { };
    
    virtual void drop() { };
    
    // ...
    
    
protected:
    
    unsigned long identifier;
    
    std::string name;
    
};

#endif /* InteractiveObject_h */
