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


/* Action helper structure */

Action::Action(const Keyword &keyword, const string &desc)
    : keyword(keyword),
    description(Description(desc))
{ }


std::pair<Keyword, Description> Action::toPair() const {
    return {keyword, description};
}










/* Object's Actions Constructors */
    
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
    
    OStream stream;
    auto iterator = this->env.begin();

    stream << (*iterator).first;
    // iterator++;
    
    auto end = this->env.end();
    auto delimiter = ui::text::styles::CS;
    for (iterator++; iterator != end; iterator++) {
    // while (iterator != this->env.end()) {
        stream << delimiter << (*iterator).first;
        // iterator++;
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

size_type Actions::size() const noexcept {
    return this->env.size();
}
    



/* Operators */

Actions& Actions::operator=(Actions &&other) noexcept {
    this->env = std::move(other.env);
    return *this;
}

Actions& Actions::operator=(const Actions &other) noexcept {
    this->env = other.env;
    return *this;
}


bool Actions::operator==(Actions &&other) const noexcept {
    return (this->env == other.env);
}

bool Actions::operator==(const Actions &other) const noexcept {
    return (this->env == other.env);
}




/* */

void Actions::clear() noexcept {
    this->env = Interactions();
}


} /* namespace items */
