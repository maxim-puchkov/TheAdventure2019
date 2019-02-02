//
//  cmd.cpp
//  cmd scheme
//
//  Created by admin on 2019-01-30.
//  Copyright © 2019 maximpuchkov. All rights reserved.
//


#include "Functor.h"
#include "Command.h"
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

int X(int x1, int x2) {
    print("Arguments on call: ");
    print(x1, x2);
    print("");
    return 1;
}

class Aclass {
public:
    /* static */ int Login(string, string) {
        return 2;
    }
    static bool Logout(string s) {
        print("call logout: ", s);
        return s == "a";
        //return (s == "hello");
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
        f1(1);
    } catch (int i) { print(i); } // Error 5
    
    try {
        auto f1 = createCommand(Test, 1);
    } catch (int i) { print(i); } // OK
    
    try {
        auto f1 = createCommand(Test, 2);
    } catch (int i) { print(i); } // OK
    
    
    
    // 2. Create command X(int, int)
    
    try {
        auto f2 = createCommand(X, 1, 2, 3, 4, 5);  // Error
        f2(2, 10000);                               // Not reachable
    } catch (int i) { print(i); }                   // Caught
    
    try {
        auto f2 = createCommand(X, 1);              // Error
        f2(2, 10000);                               // Not reachable
    } catch (int i) { print(i); }                   // Caught
    
    try {
        auto f2 = createCommand(X, 2, 10000);       // OK
        f2(2, 10000);                               // Calls X(2, 10000)
    } catch (int i) { print(i); }                   // No errors
    
    
    
    
    // auto f3 = createFunctor(Accounts.Login);
    
    string input4 = "user";
    try {
        auto f4 = createCommand(Accounts.Logout, "a"); //input4);
        bool res4 = f4("a");
        print(res4 == true ? "Logout ok" : "Error");
    } catch (int i) { print(i); }

    
    auto f5 = createFunctor(Game.send);

    
    print("OK");
    return 0;
}





#include "User.h"
using user::User; // !

User login(string u, string p) {
    User user(u, p);
    return user;
}



void test_users() {
    auto cmdLogin = createCommand(login, "user", "pass");
    
    cmdLogin("user", "pass");
}



int main(int argc, const char * argv[]) {
    // test();
    test_users();
    return 0;
}
