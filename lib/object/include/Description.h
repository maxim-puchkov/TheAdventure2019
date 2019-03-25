//
//  Description.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Description_h
#define Description_h

#include "objects.hpp"

namespace objects {
    
inline namespace structures {


/*!
 @struct Description
 
 @brief Short and long descriptions of an item. If description
        is a long text, it will be broken down into multiple
        lines depending on the line width.
 */
struct Description {
public:
    
    /* Constructors */
    
    /// Empty description
    Description();
    
    /// Default constructor
    Description(const Text &source);
    
    /// Description with specified line width
    Description(const Text &source, uint16_t lineWidth);
    
    
    
    
    
    /* Description properties */
    
    /// Set description line width
    void setWidth(uint16_t width);
    
    /// Formats description according to line width
    void reformat();
    
    /// Clear all text
    void clear();
    
    
    
    
    
    /* Retrieval */
    
    /// Retrieve short description
    Text brief() const;
    
    /// Retrieve long description
    Text full() const;
    
    
    
    
    
    /* Operators */
    
    bool operator==(Description &other) const;
    bool operator==(const Description &other) const;
    
private:
    
    /// First 2-3 words of full description
    Text shortdesc;
    
    /// Full description broken down into lines of
    /// specified length
    vector<Text> longdesc;
    
    /// Source string is saved to allow reformatting
    Text source;
    
    /// Width of one line
    uint16_t width;
    

    
    
    
    /*!
     @function textWords
     @return Vector of individual source text words without whitespaces.
     */
    vector<string> textWords() const;
    
    
    /*!
     @function toString
     @param words Vector of words
     @return Line of text
     */
    Text toString(vector<string> &&words) const;
    
    
    /*!
     @function breakLines
     @param words Partitioned words of full text input
     @return Lines of words with specified width
     */
    vector<Text> partition(const vector<Text> &words) const;
    
    
};


} /* namespace structures */

} /* namespace objects */

#endif /* Description_h */
