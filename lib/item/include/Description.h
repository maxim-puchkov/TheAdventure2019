//
//  Description.h
//  adventure2019
//
//  Created by admin on 2019-03-05.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef Description_h
#define Description_h

#include "items.hpp"
//#include "ObjectData.h"


namespace items {


/*!
 @class Description
 
 @brief Short and long descriptions
 
 Brief (short) and full (long) descriptions of an item.
 If description is too long to fit on a line, it will be
 broken down into multiple lines depending on the line width.
 */
class Description: public objects::ObjectData<Description> {
public:
    
    static const Text DEFAULT_DESCRIPTION_TEXT;
    static const Description DEFAULT_INSTANCE;
    
    
    /* Constructors */
    
    /*! Empty description */
    Description();
    
    /*! Description from text */
    Description(const Text &source);
    
    /*! Description from text block containing multiple lines */
    Description(const TextBlock &block);
    
    /*! Description with specified line width */
    Description(const Text &source, std::size_t width);
    
    
    
    
    
    /* ObjectData Protocol */
    
    // Description& reset() noexcept override;
    
    std::size_t size() const noexcept override;
    
    string toString() const noexcept override;
    
    vector<string> toVector() const noexcept override;
    
    
    
    
    
    /* Description properties */
    
    /*! Set description line width */
    void setWidth(std::size_t width);
    
    /*! Overwrite brief description (shortdesc) */
    void setBrief(const Text &description);
    
    /*! Overwrite full description (longdesc) */
    void setFull(const TextBlock &description);
    
    
    
    
    /* Retrieval */
    
    /*! Short description */
    Text brief() const;
    
    /*! Long description combined to one string */
    Text full() const;
    
    /*! Retrieve total line count of long description */
    std::size_t lineCount() const;
    
    /*! Retrieve width of the first line */
    std::size_t lineWidth() const;
    
    
    
    
    
    /* Operators */
    
    bool operator==(Description &other) const;
    bool operator==(const Description &other) const;
    
    TextLine& operator[](std::size_t index);
    TextLine operator[](std::size_t index) const;
    
private:
    
    /*! Short description is the first line of full description (mutable) */
    Text shortdesc;
    
    /*! Full description breaks down source text into a vector
     of text lines, such that every line fits on a line (mutable) */
    TextBlock longdesc;
    
    /*! Number of description text characters that can fit on a line (mutable) */
    std::size_t width;
    
private:
    
    
    void init();
    
    [[deprecated]] Text cut() const;
    
    bool validate() const noexcept;
    
    /*! Clear descriptions */
    void clear() noexcept override;
    
    /*! Generate default object of this class */
    //objects::ObjectData<Description>::default_object() const noexcept override {
    //Description default_object() const noexcept override;
    
    //Description& reset() noexcept override;
    
    Description default_data_instance() const noexcept override;
    
    /*! Description original source text */
    UIText source;
    
};


} /* namespace items */

#endif /* Description_h */
