//
//  Description.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Description_h
#define Description_h

#include <string>
#include <vector>

using std::string;
using std::vector;

static string EMPTY = "";




namespace objects::data::structures {


/**
 @class Description
 
 @brief Short and long descriptions of an item. If description
        is a long text, it will be broken down into multiple
        lines depending on the line width.
 */
class Description {
public:
    
    Description();
    
    Description(const string &shortdesc,
                const vector<string> &longdesc);
    
    Description(string description,
                int shortdescWidth,
                int lineWidth); /* undefined */
    
    /// Clear all text
    void clear();
    
    /// Retrieve short description
    string getShort() const;
    
    /// Retrieve long description
    vector<string> getLong() const;
    
private:
    
    string shortdesc;
    
    vector<string> longdesc;
    
};



} /* namespace objects::data::structures */

#endif /* Description_h */
