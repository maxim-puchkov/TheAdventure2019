//
//  Identifier.cpp
//  Authentication
//  com.maximpuchkov.Faworki.adventure2019.Identifier
//
//  Package:             Authentication
//  Project:             adventure2019
//  Workspace:           Faworki
//  Organization:        maximpuchkov
//  Prefix:              com
//
//  Author:              Maxim Puchkov (mpuchkov@sfu.ca)
//  Full username:       admin
//  Created on:          2019-03-17 at 12:05 PM
//  System:              macOS 10.13
//  Tools:               Xcode v.10.1 (10B61); Swift 4.0
//
//  Created by admin (Maxim Puchkov).
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "UUID.h"


template<typename T>
T UUID<T>::generate() {
    return ++this->current;
}
