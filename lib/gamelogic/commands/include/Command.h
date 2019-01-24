/////////////////////////////////////////////////////////////////////////////
//                                  Command
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

template<typename T>
struct Command {
    
    constexpr auto operator()(T &&ts);
    
    constexpr std::add_const_t<T>& as_const(T &ts) noexcept;
    
    auto eval(T &&ts);
    
    auto defineNew(T &&ts);
    
    Command& operator=(const Command &) = delete;
    
    Command& operator=(Command &&) = default;
    
};
