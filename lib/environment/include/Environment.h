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
#include "convertible.h"


using std::string;
using std::unordered_map;


const string ENV_BIND_ERROR = "Map Environment error: Key is already defined.";
const string ENV_FIND_ERROR = "Map Environment error: Unable to find specified key.";
const string ENV_CONV_ERROR = "Map Environment error: Template argument does not have .toString() function.";


/*!
 *  @class Environment
 *
 *  @brief Custom safe map environment.
 *
 *  Binds search key K to value V.
 *  Most operations validate the key and
 *  throw exceptions if invalid.
 *  Required by Cmd-Processor to evaluate input.
 *  Potentially needed to track users.
 */
template<class K, class V>
class Environment {
public:
    
    /* Constructors */
    
    Environment() = default;
    
    Environment(const Environment &other);
    
    Environment(Environment &&other) noexcept;
    
    ~Environment() = default;
    
    
    
    /* Map operations */
    
    /*! Lookup value by search key */
    V lookup(const K &k) const;
    
    /*! Lookup value by search key */
    V lookup(K &&k) const;
    
    /*! Lookup values by composite search key */
    // std::queue<V>
    
    /* Bind key to value */
    void bind(const K &k, const V &v);
    
    /*! Bind a pair of key and value */
    void bind(const std::pair<const K, V> &binding);
    
    /*! Bind a pair of key and value */
    void bind(std::pair<const K, V> &&binding);
    
    /*! Unbind key */
    void unbind(const K &k);
    
    /*! Modify key's value */
    void modify(const K &k, const V &v);
    
    /*! Check if a key exists in the environment */
    bool exists(const K &k) const noexcept;
    
    /*! */
    void validate(const K &k) const noexcept(false);
    
    /*! Clear all data */
    void clear() noexcept;
    
    bool empty() const noexcept;
    
    typename unordered_map<K, V>::const_iterator find(const K &k) const noexcept(false);
    
    typename unordered_map<K, V>::size_type size() const;
    
    
    
    
    
    /* Retrieval */
    
    std::queue<const K> keys() const;
    
    std::queue<std::pair<const K, V>> pairs() const;
    
    
    
    
    
    
    /* Convert */
    
    std::string toString() const noexcept;
    
    
    
    
    
    /* Iterator */
    
    typename unordered_map<K, V>::const_iterator begin() const;
    typename unordered_map<K, V>::const_iterator end() const;
    
    
    
    
    
    
    /* Operators */
    
    Environment<K, V>& operator=(Environment<K, V> &&other) noexcept;
    Environment<K, V>& operator=(const Environment<K, V> &other);
    
    bool operator==(Environment<K, V> &other) const;
    bool operator==(const Environment<K, V> &other) const;
    
    template<class FK, class FV>
    friend std::ostream& operator<<(std::ostream &stream, Environment<FK, FV> &env);
    
private:
    
    unordered_map<K, V> map;
    
};

#include "../src/Environment.cpp"

#endif /* Environment_h */
