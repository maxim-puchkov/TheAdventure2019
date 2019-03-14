//
//  ItemDescription.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef ItemDescription_h
#define ItemDescription_h

#include "Object.h"


/**
 @class ItemDescription
 
 @description
    Short and long descriptions of an item.
    If description is a long text, it will be broken down into multiple lines
        depending on the line width.
 */
class ItemDescription {
public:
    
    ItemDescription();
    ItemDescription(const string &shortdesc, const vector<string> &longdesc);
    ItemDescription(objects::Text description, int shortdescWidth, int lineWidth); /* undefined */
    
    string getShort() const;
    vector<string> getLong() const;
    
private:
    
    string shortdesc;
    vector<string> longdesc;
    
};


#endif /* ItemDescription_h */
