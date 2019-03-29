//
//  ObjectDataStructure .cpp
//  adventure2019: Object
//  com.maximpuchkov.Faworki.adventure2019.ObjectDataStructure
//
//  Created by mpuchkov on 2019-03-28. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "ObjectDataStructure.h"

using objects::ObjectDataStructure;


template<typename T>
T& ObjectDataStructure<T>::data() {
    return *static_cast<T*>(this);
}

template<typename T>
std::ostream& operator<<(std::ostream &stream, T structure) {
    stream << ObjectDataStructure<T>::data().toString();
    return stream;
}
