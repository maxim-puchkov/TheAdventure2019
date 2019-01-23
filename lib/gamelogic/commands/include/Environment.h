/////////////////////////////////////////////////////////////////////////////
//                              Environment
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Environment_h
#define Environment_h

#include <map>

const std::string ENV_BINDING_ERROR = "Environment error: Not found.";

/**
 *  @class Environment
 *
 *  @brief Environment binding E to search key T. Validates if needed.
 */
template<class T, class E>
class Environment {
public:
    
    void bind(const T &t, const E &e) {
        this->map[t] = e;
    }
    
    E lookup(const T &t) {
        return this->map[t];
    }
    
    E safe_lookup(const T &t) {
        E e = this->map[t];
        validate(e);
        return e;
    }
    
private:
    
    void validate(const E &e) throw() {
        if (e == nullptr) {
            throw this->exception;
        }
    }
    
    std::map<T, E> map;
    std::invalid_argument exception = std::invalid_argument(ENV_BINDING_ERROR);
    
};


#endif /* Environment_h */
