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
    
    // Constructors
    
    /// Empty description
    Description();
    
    Description(const Text &source);
    
    /// Break up description text into multiple lines.
    Description(const Text &source, uint16_t lineWidth);
    
    
    
    
    
    // Mutators
    
    /// Set description line width
    void setWidth(uint16_t width);
    
    /// Formats description according to line width
    void reformat();
    
    /// Clear all text
    void clear();
    
    
    
    
    
    //
    
    /// Retrieve short description
    Text brief() const;
    
    /// Retrieve long description
    //vector<Text> full() const;
    Text full() const;
    
    
    
    
    
    // Operators
    
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
     @function breakLines
     @param words Partitioned words of full text input
     @return Lines of words with specified width
     */
    vector<Text> breakLines(const vector<Text> &words) const;
    
    
};


} /* namespace structures */

} /* namespace objects */

#endif /* Description_h */
