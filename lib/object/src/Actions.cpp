//
//  Actions.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Actions
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "Actions.h"

using namespace objects;

Actions::Actions()
: env(Environment<Key, Description>{})
{ }

Actions::Actions(const vector<pair<string, string>> &actions)
: env(Environment<Key, Description>{}) {
    for (auto &pair : actions) {
        Key keyword = pair.first;
        Description description = Description(pair.second);
        
        this->env.bind(keyword, description);
    }
}

void Actions::clear() {
    this->env.clear();
}


bool Actions::operator==(Actions &other) const {
    return (this->env == other.env);
}

bool Actions::operator==(const Actions &other) const {
    return (this->env == other.env);
}
