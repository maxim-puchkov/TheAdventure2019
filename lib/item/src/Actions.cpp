//
//  Actions.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.Actions
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "Actions.h"


namespace items {

const std::initializer_list<Action> Actions::ACTIONS_IL = std::initializer_list<Action>{};
const Actions Actions::DEFAULT_INSTANCE = Actions(ACTIONS_IL);


/* Action helper structure */

Action::Action(const Keyword &keyword, const string &desc)
: keyword(keyword), description(Description(desc))
{ }

inline pair<Text, Description> Action::toPair() const {
    return {keyword, description};
}










/* Object's Actions environment Constructors */
    

Actions::Actions(const vector<pair<string, string>> &actions) {
    for (auto &pair : actions) {
        Text keyword = pair.first;
        Description description = Description(pair.second);
        this->env.bind(keyword, description);
    }
}


Actions::Actions(const vector<Action> &actions) {
    for (auto &action : actions) {
        this->add(action);
    }
}





/* ObjectData Protocol */

string Actions::toString() const noexcept {
    if (this->env.empty()) {
        return EMPTY;
    }
    
    data_ostream stream;
    auto iterator = this->env.begin();

    stream << (*iterator).first;
    iterator++;
    
    auto delimiter = ui::text::styles::CS;
    while (iterator != this->env.end()) {
        stream << delimiter << (*iterator).first;
        iterator++;
    }
    
    return stream.str();
}


vector<string> Actions::toVector() const noexcept {
    vector<string> vec;
    for (auto &bind : this->env) {
        vec.push_back(bind.first);
        vec.push_back(bind.second.toString());
    }
    return vec;
}





/* Environment functions */

void Actions::add(const Action &action) {
    this->env.bind(action.toPair());
}


bool Actions::empty() const {
    return this->env.empty();
}


bool Actions::isInteractable() const noexcept {
    return (!this->env.empty());
}


std::size_t Actions::size() const noexcept {
    return this->env.size();
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


void Actions::clear() noexcept {
    this->env.clear();
}

Actions Actions::default_data_instance() const noexcept {
    return Actions::DEFAULT_INSTANCE;
}

} /* namespace items */
