/////////////////////////////////////////////////////////////////////////////
//                                  Environment
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Environment_cpp
#define Environment_cpp

#include "Environment.h"
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


template<class K, class V>
Environment<K, V>::Environment()
{ }


template<class K, class V>
Environment<K, V>::Environment(const Environment &other)
: map(std::move(other.map))
{ }


template<class K, class V>
Environment<K, V>::Environment(Environment &&other)
: map(std::move(other.map))
{ }


template<class K, class V>
Environment<K, V>::~Environment()
{ }


template<class K, class V>
void Environment<K, V>::bind(const K &k, const V &v) {
    this->validate(k);
    this->map.insert(std::pair<const K, V>(k, v));
}


template<class K, class V>
void Environment<K, V>::bind(const std::pair<const K, V> &binding) {
    this->validate(binding.first);
    this->map.insert(binding);
}


template<class K, class V>
void Environment<K, V>::unbind(const K &k) {
    auto it = this->find(k);
    this->map.erase(it);
}


template<class K, class V>
void Environment<K, V>::modify(const K &k, const V &v) {
    auto it = this->find(std::forward(k));
    it->second = v;
}


template<class K, class V>
V Environment<K, V>::lookup(const K &k) const {
    auto it = this->find(k);
    return it->second;
}


template<class K, class V>
bool Environment<K, V>::exists(const K &k) const noexcept {
    auto it = this->map.find(k);
    if (it == this->map.end()) {
        return false;
    }
    return true;
}


template<class K, class V>
void Environment<K, V>::validate(const K &k) const noexcept(false) {
    if (this->exists(k)) {
        throw std::invalid_argument(ENV_BIND_ERROR);
    }
}


template<class K, class V>
void Environment<K, V>::clear() noexcept {
    this->map.clear();
}


template<class K, class V>
typename unordered_map<K, V>::const_iterator Environment<K, V>::find(const K &k) const noexcept(false) {
    auto it = this->map.find(k);
    if (it == this->map.end()) {
        throw std::invalid_argument(ENV_FIND_ERROR);
    }
    return it;
}


template<class K, class V>
typename unordered_map<K, V>::size_type Environment<K, V>::size() const {
    return this->map.size();
}


template<class K, class V>
std::queue<const K> Environment<K, V>::keys() const {
    std::queue<const K> keys;
    auto it = this->begin();
    while (it != this->end()) {
        keys.push(it->first);
        it++;
    }
    return keys;
}


template<class K, class V>
std::queue<std::pair<const K, V>> Environment<K, V>::pairs() const {
    std::queue<std::pair<const K, V>> pairs;
    auto it = this->begin();
    while (it != this->end()) {
        pairs.push(std::pair<const K, V>(it->first, it->second));
        it++;
    }
    return pairs;
}


template<class K, class V>
typename unordered_map<K, V>::const_iterator Environment<K, V>::begin() const {
    return this->map.cbegin();
}


template<class K, class V>
typename unordered_map<K, V>::const_iterator Environment<K, V>::end() const {
    return this->map.cend();
}


template<class K, class V>
Environment<K, V>& Environment<K, V>::operator=(Environment<K, V> &other) {
    this->map = other.map;
    return *this;
}


template<class K, class V>
Environment<K, V>& Environment<K, V>::operator=(const Environment<K, V> &other) {
    this->map = other.map;
    return *this;
}


template<class K, class V>
bool Environment<K, V>::operator==(Environment<K, V> &other) const {
    return (this->map == other.map);
}


template<class K, class V>
bool Environment<K, V>::operator==(const Environment<K, V> &other) const {
    return (this->map == other.map);
}

#endif /* Environment_cpp */
