/////////////////////////////////////////////////////////////////////////////
//                                  Command
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Command.h"

template<typename T>
constexpr auto &Command<T>::as_const(T &ts) noexcept {
    return ts;
}

template<typename T>
auto defineNew(T &&t, T &&ts) {
    return [=] { test(t, ts); };
}

template<typename T>
constexpr auto Command<T>::operator()(T &&ts) {
    const T t = &ts;
    
    [=] { std::cout << "New func" << std::endl; };
    
    [=] { };
    
    [&, t] { cmdFn(ts); };
    
    const auto &ct = t;
    [&, ct] { };
}

template<typename T>
auto Command<T>::eval(T &&ts) {
    return [](auto &&ts) {
        command(std::forward<decltype(ts)>(ts));
        return [=] {
            args(ts);
        };
    };
}
