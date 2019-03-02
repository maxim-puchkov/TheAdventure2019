//
//  UIColorTerminal.cpp
//  adventure2019
//
//  Created by admin on 2019-02-04.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef UIColor_cpp
#define UIColor_cpp


#include "UIColor.h"
#include "iostream"
using std::cout;


/*
 *  ANSI escape codes will change
 *  terminal text color
 */
void blue() {
    cout << "\u001b[34m";
}

void red() {
    cout << "\u001b[31m";
}

void reset() {
    cout << "\u001b[0m";
}


#endif /* UIColor_cpp */
