/////////////////////////////////////////////////////////////////////////////
//                                  Command
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

template<typename T>
struct Command {
    
    constexpr auto& as_const(T &ts) noexcept;
    
    auto eval(T &&ts);
    
    auto defineNew(T &&ts);
    
    constexpr auto operator()(T &&ts);
    
    Command& operator=(const Command &) = delete;
    
    Command& operator=(Command &&) = default;
    
};
