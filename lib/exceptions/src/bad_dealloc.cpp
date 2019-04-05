//
//  bad_dealloc.cpp
//  Objects: Exceptions
//  com.maximpuchkov.Objects.Objects.bad_dealloc
//
//  Created by mpuchkov on 2019-03-31. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "bad_dealloc.h"


bad_dealloc::bad_dealloc(const std::string& what_arg)
: std::runtime_error(what_arg)
{ }


bad_dealloc::bad_dealloc(const char* what_arg)
: std::runtime_error(what_arg)
{ }
