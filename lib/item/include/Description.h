//
//  Description.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Description_h
#define Description_h

#include "ObjectData.h"
#include "UIText.h"


namespace items {

inline namespace data {

using Text = string;


/*!
 @class Description
 
 @brief Short and long descriptions
 
 Brief (short) and full (long) descriptions of an item.
 If description is too long to fit on a line, it will be
 broken down into multiple lines depending on the line width.
 */
class Description: public objects::ObjectData<Description> {
public:
    
    /* Constructors */
    
    /*! Empty description */
    Description();
    
    /*! Description from text */
    Description(const Text &source);
    
    /*! Description from multiple text lines */
    Description(const vector<Text> &source);
    
    /*! Description with specified line width */
    Description(const Text &source, uint16_t lineWidth);
    
    
    
    
    
    /* ObjectData Protocol */
    
    string toString() const noexcept override;
    
    vector<string> toVector() const noexcept override;
    
    
    
    
    
    /* Description properties */
    
    /*! Set description line width */
    void setWidth(uint16_t width);
    
    /*! Overwrite brief description */
    void setBrief(const Text &description);
    
    /*! Overwrite full description */
    void setFull(const vector<Text> &description);
    
    /*! Clear all descriptions */
    void clear();
    
    
    
    
    
    /* Retrieval */
    
    /*! Retrieve short description */
    Text brief() const;
    
    /*! Retrieve long description */
    Text full() const;
    
    /*! Retrieve total line count of long description */
    size_t lineCount() const;
    
    /*! Retrieve width of the first line */
    size_t lineWidth() const;
    
    
    
    
    
    /* Operators */
    
    bool operator==(Description &other) const;
    bool operator==(const Description &other) const;
    
    Text operator[](size_t index);
    Text operator[](size_t index) const;
    
private:
    
    void init();
    
    Text cut() const;
    
    /// Source string is saved to allow reformatting
    ui::UIText source;
    
    /// First line of long description
    Text shortdesc;
    
    /// Full description broken down into lines of
    /// specified length
    vector<Text> longdesc;
    
    /// Width of one line
    size_t width;
    
};


} /* namespace data */

} /* namespace items */

#endif /* Description_h */
