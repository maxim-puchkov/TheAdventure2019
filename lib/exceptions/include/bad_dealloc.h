//
//  bad_dealloc.h
//  Objects: Objects
//  com.maximpuchkov.Objects.Objects.bad_dealloc
//
//  Created by mpuchkov on 2019-03-31. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#ifndef bad_dealloc_h
#define bad_dealloc_h

#include <exception>
#include <string>


class bad_dealloc: public std::runtime_error {
public:
    explicit bad_dealloc(const std::string& what_arg);
    explicit bad_dealloc(const char* what_arg);
};


#endif /* bad_dealloc_h */
