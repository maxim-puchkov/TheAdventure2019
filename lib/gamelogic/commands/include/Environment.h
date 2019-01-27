/////////////////////////////////////////////////////////////////////////////
//                              Environment
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Environment_h
#define Environment_h

#include <exception>
#include <map>
#include <iostream>
#include <string>

using std::string;

const string ENV_BINDING_ERROR = "Map Environment error: Search key is not created.";

/**
 *  @class Environment
 *
 *  @brief Environment binding E to search key T. Validates if needed.
 */
template<class T, class E>
class Environment {
public:
    
    Environment() {}
    
    ~Environment() {}
    
    void bind(const T t, const E e) {
        this->map.insert(std::pair<T, E>(t, e));
    }
    
    E lookup(const T &t) {
        auto it = this->map.find(t);
        if (it != this->map.end()) {
            return it->second;
        }
        throw std::invalid_argument(this->exceptionText);
    }
    
    void setExceptionText(const string &text) {
        this->exceptionText = text;
    }
    
private:
    
    std::map<T, E> map;
    std::string exceptionText = ENV_BINDING_ERROR;
    
};

#endif /* Environment_h */
