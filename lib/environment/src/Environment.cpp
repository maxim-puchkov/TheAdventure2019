/////////////////////////////////////////////////////////////////////////////
//                                  Environment
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Environment_cpp
#define Environment_cpp

#include "Environment.h"


/* Copy, Move constructors */

template<class K, class V>
Environment<K, V>::Environment(const Environment &other)
: map(other.map)
{ }


template<class K, class V>
Environment<K, V>::Environment(Environment &&other) noexcept
: map(std::move(other.map))
{ }




/* Map operations */

template<class K, class V>
void
Environment<K, V>::bind(const K &k, const V &v) {
    this->validate(k);
    this->map.insert(std::pair<const K, V>{k, v});
}

template<class K, class V>
void
Environment<K, V>::bind(K &&k, V &&v) {
    this->validate(k);
    this->map.insert(std::pair<const K, V>{std::move(k), std::move(v)});
}

template<class K, class V>
void
Environment<K, V>::bind(const std::pair<const K, V> &binding) {
    this->validate(binding.first);
    this->map.insert(binding);
}

template<class K, class V>
void
Environment<K, V>::bind(std::pair<const K, V> &&binding) {
    this->validate(binding.first);
    this->map.insert(std::move(binding));
}


template<class K, class V>
void
Environment<K, V>::unbind(const K &k) {
    auto it = this->find(k);
    this->map.erase(it);
}


template<class K, class V>
V
Environment<K, V>::lookup(const K &k) const {
    auto it = this->find(k);
    return it->second;
}


template<class K, class V>
V
Environment<K, V>::lookup(K &&k) const {
    auto it = this->find(std::forward<K>(k));
    return it->second;
}




/* Additional map operations */

template<class K, class V>
void
Environment<K, V>::modify(const K &k, const V &v) {
    this->map[k] = v;
}


template<class K, class V>
bool
Environment<K, V>::exists(const K &k) const noexcept {
    auto it = this->map.find(k);
    return (it != this->map.end());
}


template<class K, class V>
bool
Environment<K, V>::empty() const noexcept {
    return this->map.empty();
}


template<class K, class V>
typename std::unordered_map<K, V>::size_type
Environment<K, V>::size() const noexcept {
    return this->map.size();
}




/* Collection retrieval */

template<class K, class V>
std::queue<const K>
Environment<K, V>::keys() const {
    std::queue<const K> keys;
    auto it = this->begin();
    while (it != this->end()) {
        keys.push(it->first);
        it++;
    }
    return keys;
}


template<class K, class V>
std::queue<std::pair<const K, V>>
Environment<K, V>::pairs() const {
    std::queue<std::pair<const K, V>> pairs;
    for (auto &pair : this) {
        pairs.push(pair);
    }
    return pairs;
    
//    auto it = this->begin();
//    while (it != this->end()) {
//        pairs.push(std::pair<const K, V>(it->first, it->second));
//        it++;
//    }
//    return pairs;
}





/* Convert */

template<class K, class V>
std::string
Environment<K, V>::toString() const noexcept {
    bool convertibleK = (__convertible<K>::to_string || std::is_arithmetic<K>::value);
    bool convertibleV = (__convertible<V>::to_string || std::is_arithmetic<V>::value);
    
    if (!convertibleK || !convertibleV) {
        return ENV_CONV_ERROR;
    }
    
    std::ostringstream stream({""});
    stream << "{";
    auto it = this->begin();
    
    stream << (*it).second.toString();
    it++;
    
    while (it != this->end()) {
        stream << ", (";
        stream << (*it).second.toString();
        stream << ")";
        
        it++;
    }
    
    stream << "}";
    return stream.str();
}





/* Iterator */

template<class K, class V>
typename std::unordered_map<K, V>::const_iterator
Environment<K, V>::find(const K &k) const noexcept(false) {
    auto it = this->map.find(k);
    if (it == this->map.end()) {
        throw std::invalid_argument(ENV_FIND_ERROR);
    }
    return it;
}


template<class K, class V>
typename std::unordered_map<K, V>::const_iterator
Environment<K, V>::begin() const {
    return this->map.cbegin();
}

template<class K, class V>
typename std::unordered_map<K, V>::const_iterator
Environment<K, V>::end() const {
    return this->map.cend();
}




/* Operators */

template<class K, class V>
Environment<K, V>&
Environment<K, V>::operator=(Environment<K, V> &&other) noexcept {
    this->map = std::move(other.map);
    return *this;
}

template<class K, class V>
Environment<K, V>&
Environment<K, V>::operator=(const Environment<K, V> &other) {
    this->map = other.map;
    return *this;
}


template<class K, class V>
bool
Environment<K, V>::operator==(Environment<K, V> &other) const {
    return (this->map == other.map);
}

template<class K, class V>
bool
Environment<K, V>::operator==(const Environment<K, V> &other) const {
    return (this->map == other.map);
}




/* Friends */

template<class FK, class FV>
std::ostream&
operator<<(std::ostream& stream, Environment<FK, FV>& env) {
    stream << env.toString();
    return stream;
}




/* * * Private * * */

template<class K, class V>
void
Environment<K, V>::validate(const K &k) const noexcept(false) {
    if (this->exists(k)) {
        throw std::invalid_argument(ENV_BIND_ERROR);
    }
}


template<class K, class V>
void
Environment<K, V>::clear() noexcept {
    this->map.clear();
}


#endif /* Environment_cpp */
