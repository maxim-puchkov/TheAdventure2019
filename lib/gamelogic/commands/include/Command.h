/////////////////////////////////////////////////////////////////////////////
//                                  Command
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

template<typename T>
struct Command {
    
    Command() {
        
    }
    
    constexpr auto& as_const(T &ts) noexcept;
    
    T eval(const T &ts);
    
    T eval(T &&ts);
    
    auto defineNew(T &&ts);
    
    constexpr auto operator()(T &&ts);
    
    //
    //    int handleoperator=(T &&...ts) {
    //        return all(ts);
    //    };
    
    
    
};
