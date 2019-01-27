/////////////////////////////////////////////////////////////////////////////
//                                  Command
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Command.h"
using std::string;

// generic template with one parameter
template<typename T>
auto vglambda = [](auto printer) {
    
};

// generic template with list
void print(string str) {
    std::cout << str << std::endl;
}

template<typename T, typename E>
void all(T t, E es) {
    print(t);
    auto token = [=](T &&t) {
        
        auto e = [=](E e) {};
        
        return [=](auto&&... es) { // generic lambda, ts is a parameter pack
            printer(std::forward<decltype(e)>(es)...);
            return [=]() { print(es...); }; // capture-less lambda
        };
    };
}

/*template<typename T>
 constexpr auto all(T t, E es):operator()(T &&ts) {
 const T t = &ts;
 
 
 [=] { std::cout << "New func" << std::endl; };
 
 [=] { };
 
 [&, t] { cmdFn(ts); };
 
 const auto &ct = t;
 [&, ct] { };
 }
 */

template<typename T>
int args(T &&t) {
    print("X");
}

template<typename T>
T eval(const T &ts) {
    return [=](auto &&... ts) {
        command(std::forward<decltype(ts)>(ts)...);
        return [=] {
            args(ts...);
        };
    };
}

template<typename T>
T Command<T>::eval(T &&ts) {
    return [=](auto &&... ts) {
        command(std::forward<decltype(ts)>(ts)...);
        return [=] {
            args(ts...);
        };
    };
}
