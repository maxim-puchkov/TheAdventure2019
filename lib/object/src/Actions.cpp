//
//  Actions.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Actions
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "Actions.h"


namespace objects {

inline namespace actions_defaults {
    const Text DISPLAY_PREFIX = "Actions: ";
    const Text ENV_DELIMITER = ", ";
}


/* Action helper structure */

Action::Action(const string &keyword, const string &desc)
: keyword(keyword), description(Description(desc))
{ }

Action::Action(const string &keyword, const vector<string> &longdesc)
: keyword(keyword), description(Description(longdesc))
{ }

pair<Key, Description> Action::toPair() {
    return {keyword, description};
}




/* Object's Actions environment Constructors */

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





/* ObjectData Protocol */

string Actions::toString() const noexcept {
    std::ostringstream stream{""};
    
    auto iterator = this->env.begin();
    stream << (*iterator).first;
    iterator++;
    
    auto delimiter = ENV_DELIMITER;
    while (iterator != this->env.end()) {
        stream << delimiter << (*iterator).first;
        iterator++;
    }
    
    return stream.str();
}


vector<string> Actions::toVector() const noexcept {
    vector<string> vec = {};
    for (auto &bind : this->env) {
        vec.push_back(bind.first);
        vec.push_back(bind.second.toString());
    }
    return vec;
}





/* Environment functions */

void Actions::add(Action &&action) {
    this->env.bind(action.toPair());
}

void Actions::clear() {
    this->env.clear();
}





/* Operators */

Actions& Actions::operator=(Actions &other) {
    this->env = other.env;
    return *this;
}

Actions& Actions::operator=(const Actions &other) {
    this->env = other.env;
    return *this;
}


bool Actions::operator==(Actions &other) const {
    return (this->env == other.env);
}

bool Actions::operator==(const Actions &other) const {
    return (this->env == other.env);
}


} /* namespace objects */
