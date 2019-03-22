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
#include <string>
#include <exception>
#include <queue>


using std::string;
using std::unordered_map;


const string ENV_BIND_ERROR = "Map Environment error: Key is already defined.";
const string ENV_FIND_ERROR = "Map Environment error: Unable to find specified key.";


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
    
    Environment();
    
    Environment(const Environment &other);
    
    Environment(Environment &&other);
    
    ~Environment();
    
    
    
    /* Operations */
    
    V lookup(const K &k) const;
    
    void bind(const K &k, const V &v);
    
    void bind(const std::pair<const K, V> &binding);
    
    void unbind(const K &k);
    
    void modify(const K &k, const V &v);
    
    bool exists(const K &k) const noexcept;
    
    void validate(const K &k) const noexcept(false);
    
    typename unordered_map<K, V>::const_iterator find(const K &k) const noexcept(false);
    
    typename unordered_map<K, V>::size_type size() const;
    
    
    
    /* Retrieval */
    
    std::queue<const K> keys() const;
    
    std::queue<std::pair<const K, V>> pairs() const;
    
    
    
    /* Custom iterator retrieval */
    
    typename unordered_map<K, V>::const_iterator begin() const;
    
    typename unordered_map<K, V>::const_iterator end() const;
    
private:
    
    unordered_map<K, V> map;
    
};

#include "Environment.cpp"

#endif /* Environment_h */
