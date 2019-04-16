/////////////////////////////////////////////////////////////////////////////
//                              Environment
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Environment_h
#define Environment_h

#include <unordered_map>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <exception>
#include <queue>
#include <type_traits>
#include "traits__convertible.h"


const std::string ENV_BIND_ERROR = "Environment exception: unable to bind a key which is already defined.";
const std::string ENV_FIND_ERROR = "Environment exception: unable to find specified key.";
const std::string ENV_CONV_ERROR = "Environment exception: template argument does not have .toString() function.";


/*!
 *  @class Environment
 *
 *  @brief Environment of game world Custom safe map environment.
 *
 *  Modified unordered map that binds search key K to value V.
 *  Exceptions may be thrown if an element already exists or not defined.
 */
template<class K, class V>
class Environment {
public:
    
    /*  Default, Copy, and Move Constructors */
    
    Environment() = default;
    Environment(const Environment &);
    Environment(Environment &&) noexcept;
    
    
    
    
    /* Map operations */
    
    /*! Create associations from map lookup Key and its Value;
     Or add existing {Key, Value} assoications to the map.  */
    void bind(const K &k, const V &v);
    void bind(K &&k, V &&v);
    void bind(const std::pair<const K, V> &binding);
    void bind(std::pair<const K, V> &&binding);
    
    /*! Delete a search key and its associated value from the map. */
    void unbind(const K &k);
    
    /*! Lookup value bound to a search key */
    V lookup(const K &k) const;
    V lookup(K &&k) const;
    
    
    
    
    
    /* Additional map operations */
    
    /*! Modify key's value */
    void modify(const K &k, const V &v);
    
    /*! Check if a key is defined in the environment */
    bool exists(const K &k) const noexcept;
    
    /*! Clear all data */
    void clear() noexcept;
    
    /*! Check if underlying map is empty */
    bool empty() const noexcept;
    
    /*! Number of stored elements */
    typename std::unordered_map<K, V>::size_type
    size() const noexcept;
    
    
    
    
    
    /* Collection retrieval */
    
    std::queue<const K> keys() const;
    
    std::queue<std::pair<const K, V>> pairs() const;
    
    
    
    
    /* Convert */
    
    std::string toString() const noexcept;
    
    
    
    
    /* Iterator */
    
    /*! Find location of a search key */
    typename std::unordered_map<K, V>::const_iterator
    find(const K &k) const noexcept(false);
    
    /*! Range-based iteration */
    typename std::unordered_map<K, V>::const_iterator
    begin() const;
    
    typename std::unordered_map<K, V>::const_iterator
    end() const;
    

    
    
    /* Operators */
    
    Environment<K, V>& operator=(Environment<K, V> &&other) noexcept;
    Environment<K, V>& operator=(const Environment<K, V> &other);
    
    bool operator==(Environment<K, V> &other) const;
    bool operator==(const Environment<K, V> &other) const;
    
    template<class FK, class FV>
    friend std::ostream& operator<<(std::ostream &stream, Environment<FK, FV> &env);
    
    
    
    
    
    ~Environment() = default;
    
private:
    
    /*! */
    void validate(const K &k) const noexcept(false);
    
    /*! */
    std::unordered_map<K, V> map;
    
};

#include "../src/Environment.cpp"

#endif /* Environment_h */
