//
//  ObjectController.h
//  adventure2019: objects
//  com.maximpuchkov.Faworki.adventure2019.ObjectController
//
//
//  Created by mpuchkov with macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef ObjectController_h
#define ObjectController_h


#include <string>
#include <vector>

#include "Environment.h"

#include "Builder.h"
#include "ObjectDataType.h"
#include "Object.h"

using std::string;
using std::vector;


namespace objects {
namespace controllers {
    


class ObjectController {
public:
    
    ObjectController();
    
private:
    
    Environment<typename, Constructor> constructors;
    
};
    

}
}

#endif /* ObjectController_h */
