/////////////////////////////////////////////////////////////////////////////
//                              Environment
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Environment_h
#define Environment_h

#include <map>

const std::string ENV_BINDING_ERROR = "Environment error: Search key is not created.";

/**
 *  @class Environment
 *
 *  @brief Environment binding E to search key T. Validates if needed.
 */
template<class T, class E>
class Environment {
public:
    
    void bind(const T t, const E e) {
        this->map.insert(std::pair<T, E>(t, e));
    }
    
    E lookup(const T &t) throw() {
        auto it = this->map.find(t);
        if (it != this->map.end()) {
            return it->second;
        }
        throw this->exception;
    }
    
private:
    
    std::map<T, E> map;
    std::invalid_argument exception = std::invalid_argument(ENV_BINDING_ERROR);
    
};


#endif /* Environment_h */
