//
//  SearchKey.h
//  Objects: Env
//  com.maximpuchkov.Objects.Objects.SearchKey
//
//  Created by mpuchkov on 2019-03-30. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef SearchKey_h
#define SearchKey_h

#include <vector>
#include <string>


bool compare(void *, void *);


template<typename T>
class SearchKey {
public:
    
    
    SearchKey(T &t)
    // h(
    {
        //std::hash<SearchKey> = hash;
    }
    
    
    void add(void *category) {//, std::function<bool(void *, void *)> comparator) {
        data.push_back(category);
        // comparators.push_back(comparator);
    }
    
    
    /// @bug
    bool operator==(SearchKey &sk) const {
        for (int i = 0; i < this->data.size(); i++) {
            if (this->data[i] == sk.data[i]) return true;
        }
        return false;
    }
    /// @bug
    bool operator==(const SearchKey &sk) const {
        for (int i = 0; i < this->data.size(); i++) {
            if (this->data[i] == sk.data[i]) return true;
        }
        return false;
    }
    
    
    
    std::vector<void *> data{};
    
    //vector<function<bool(void *, void *)>> comparators;
    
    std::hash<SearchKey> h;
    
private:
    
    
    //vector<
    
};


namespace std {
    
    
    
    /*!
     @struct
     @ignore
     */
    
    
} /* namespace std */


#endif /* SearchKey_h */
