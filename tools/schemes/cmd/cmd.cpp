//
//  cmd.cpp
//  cmd scheme
//
//  Created by admin on 2019-01-30.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//


#include "Functor.h"
#include <iostream>
using namespace std;





// Outputs: Hello, World!
void Test(int i) {
    print( "Hello, World!\n" );
}

// Outputs: Hello, <Input>!
string Test_2(std::string Input) {
    print( "Hello, " + Input + "! \n" );
    return "ret";
}

// Outputs: Login: <Login>, Password: <Password>!
void Test_3(std::string Login, std::string Password) {
    print( "Login: " + Login + ", Password: " + Password + "! \n" );
}

int X(int, int) {
    return 1;
}

class Aclass {
public:
    /* static */ int Login(string, string) {
        return 2;
    }
    static bool Logout(string s) {
        return (s == "hello");
    }
private:
    
};

namespace Aname {
    class Bclass {
    public:
        static bool send(string, char) {
            return true;
        }
    };
}




int test() {
    string input = "hello";
    Aclass Accounts;
    Aname::Bclass Game;
    
    // 1. Create command Test(int)
    
    try {
        auto f1 = createCommand(Test, 1, 2, 3, 4, 5);
    } catch (int i) { print(i); } // Error 5
    
    try {
        auto f1 = createCommand(Test, 1);
    } catch (int i) { print(i); } // OK
    
    try {
        auto f1 = createCommand(Test, 2);
    } catch (int i) { print(i); } // OK
    
    
    
    // 2. Create command X(int, int)
    
    try {
        auto f2 = createCommand(X, 1, 2, 3, 4, 5);
    } catch (int i) { print(i); } // Error 5
    
    try {
        auto f2 = createCommand(X, 1);
    } catch (int i) { print(i); } // Error 1
    
    try {
        auto f2 = createCommand(X, 2, 10000);
    } catch (int i) { print(i); } // OK
    
    
    
    
    // auto f3 = createFunctor(Accounts.Login);
    
    
    auto f4 = createFunctor(Accounts.Logout);
    print(f4.argc());
    //f4(input);
    
    auto f5 = createFunctor(Game.send);
    print(f5.argc());
    
    
    print("OK");
    return 0;
}





int main(int argc, const char * argv[]) {
    return test();
}
