//
//  UIColorWeb.cpp
//  adventure2019
//
//  Created by admin on 2019-02-04.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//

#ifndef UIColor_cpp
#define UIColor_cpp


#include "UIColor.h"
#include <iostream>
#include <string>
using std::cout;


/*
 * When/if needed should remove <font>
 * and create an actuall stylesheet
 */
static std::string font(const std::string &color) {
    return "<font color=" + font + ">";
}

void blue() {
    cout << font("blue");
}

void red(); /* undefined */

void reset(); /* undefined */   /* </font> */


#endif /* UIColor_cpp */





/*  Element
 
 <pre id="messages">
 Connected!
 107614700574880&gt;
 <font color="red"> Command not found</font>
 107614700574880&gt;
 <font color="red"> Command not found</font>
 Disconnected!
 </pre>
 
 */
