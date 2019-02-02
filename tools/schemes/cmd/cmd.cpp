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

int X() {
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
    
    auto f1 = createFunctor(Test);
    print(f1.argc());
    f1.rtype(); // PFviE
    if (typeid(f1.rtype()) != typeid(void)) return 1;
    //print(f1.rtype().name());
    
    auto f2 = createFunctor(X);
    print(f2.argc());
    if (typeid(f1.rtype()) != typeid(void)) return 2;
    
    
    // auto f3 = createFunctor(Accounts.Login);
    
    
    auto f4 = createFunctor(Accounts.Logout);
    print(f4.argc());
    if (typeid(f1.rtype()) != typeid(void)) return 3;
    
    
    auto f5 = createFunctor(Game.send);
    print(f5.argc());
    if (typeid(f1.rtype()) != typeid(void)) return 4;
    
   
    print("OK");
    return 0;
}
 
 



int main(int argc, const char * argv[]) {
    return test();
}
