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



/**
 *  @class Environment
 *
 *  @brief Environment binding E to search key T. Validates if needed.
 */
template<class K, class V>
class Environment {
public:
    
    Environment() {}
    
    Environment(const Environment &other)
    : map(std::move(other.map))
    {}
    
    Environment(Environment &&other)
    : map(std::move(other.map))
    {}
    
    ~Environment() {}
    
    void bind(const K &k, const V &v) {
        if (this->exists(k)) {
            throw std::invalid_argument(ENV_BIND_ERROR);
        }
        this->map.insert(std::pair<const K, V>(k, v));
    }
    
    void bind(const std::pair<const K, V> &binding) {
        if (this->exists(binding.first)) {
            throw std::invalid_argument(ENV_BIND_ERROR);
        }
        this->map.insert(binding);
    }
    
    void unbind(const K &k) {
        auto it = this->find(k);
        this->map.erase(it);
    }
    
    void modify(const K &k, const V &v) {
        auto it = this->find(std::forward(k));
        it->second = v;
    }
    
    V lookup(const K &k) const {
        auto it = this->find(k);
        return it->second;
    }
    
    bool exists(const K &k) const {
        auto it = this->map.find(k);
        if (it == this->map.end()) {
            return false;
        }
        return true;
    }
    
    std::queue<const K> keys() const {
        std::queue<const K> keys;
        auto it = this->begin();
        while (it != this->end()) {
            keys.push(it->first);
            it++;
        }
        return keys;
    }
    
    std::queue<std::pair<const K, V>> pairs() const {
        std::queue<std::pair<const K, V>> pairs;
        auto it = this->begin();
        while (it != this->end()) {
            pairs.push(std::pair<const K, V>(it->first, it->second));
            it++;
        }
        return pairs;
    }
    
    typename unordered_map<K, V>::const_iterator find(const K &k) const {
        auto it = this->map.find(k);
        if (it == this->map.end()) {
            throw std::invalid_argument(ENV_FIND_ERROR);
        }
        return it;
    }
    
    typename unordered_map<K, V>::size_type size() const {
        return this->map.size();
    }
    
private:
    
    unordered_map<K, V> map;
    
    typename unordered_map<K, V>::const_iterator begin() const {
        return this->map.cbegin();
    }
    
    typename unordered_map<K, V>::const_iterator end() const {
        return this->map.cend();
    }
    
};

#endif /* Environment_h */
