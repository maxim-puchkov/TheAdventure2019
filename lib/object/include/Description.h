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
#include <iterator>
#include <sstream>

namespace objects {


/*!
 @struct Description
 
 @brief Short and long descriptions of an item. If description
        is a long text, it will be broken down into multiple
        lines depending on the line width.
 */
struct Description {
public:
    
    //
    
    /// Empty description
    Description();
    
    /// Break up description text into multiple lines.
    Description(const Text &description, uint16_t lineWidth);
    
    
    
    
    
    //
    
    /// Set description line width
    void setWidth(uint16_t width) {
        this->width = width;
    }
    
    /// Formats description according to line width
    void reformat() {
        
        auto words = this->textWords();
        
        auto longdesc = this->breakLines(words);
        
    }
    
    /// Breaks up text
    /// @warning incomplete
    vector<Text> breakLines(const vector<Text> &words) {
        
        vector<Text> lines;
        
        
        std::stringstream line("");
        unsigned short lineLength = 0;
        
        
        for (auto &word : words) {
            auto wordLength = word.size();
            
            // Go to next line if cannot fit
            if (lineLength + wordLength > this->width) {
                lines.push_back(line.str());
                line.clear();
                lineLength = 0;
            }
            
            line << word;
            lineLength += wordLength;
        }
        
        return lines;
        
    }
    
    /// Clear all text
    void clear();
    
    
    
    
    
    //
    
    /// Retrieve short description
    Text brief() const;
    
    /// Retrieve long description
    vector<Text> full() const;
    
    bool operator==(Description &other) const;
    bool operator==(const Description &other) const;
    
    
    
    
    
    // Deprecated
    
    /* * * * * */
    // Assumess correct desc
    /// @ignore
    Description(const Text &desc);
    
    // Assumes correct longdesc
    /// @ignore
    Description(const string &shortdesc,
                const vector<string> &longdesc);
    
    // undefined
    /// @ignore
    Description(string description,
                int shortdescWidth,
                int lineWidth); /* undefined */
    /* * * * * */
    
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
    
    
};


} /* namespace objects */

#endif /* Description_h */
