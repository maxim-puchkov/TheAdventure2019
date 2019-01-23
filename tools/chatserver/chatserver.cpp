/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "ServerCommands.h"
#include "CommandDefinitions.h"
#include "Server.h"
#include "User.h"
#include "AccountManager.h"
#include "GameManager.h"
#include "UserManager.h"
#include "ServerCommands.h"

// #include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include <stdint.h>
#include <string>
#include <vector>


using networking::Server;
using networking::Connection;
using networking::Message;
using user::User;
using accountmanager::AccountManager;


std::vector<Connection> clients;
User userLogin{"",""};
AccountManager userManager{};


void
onConnect(Connection c) {
  std::cout << "New connection found: " << c.id << "\n";
  clients.push_back(c);
}


void
onDisconnect(Connection c) {
  std::cout << "Connection lost: " << c.id << "\n";
  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
  clients.erase(eraseBegin, std::end(clients));
}

/*std::vector<std::string> getInfo(const std::string& message){
  std::size_t pos = message.find(" ");  
  std::string userInfo = message.substr(pos + 1);
  pos = userInfo.find(" ");
  std::string uName = userInfo.substr(0, pos);
  std::string uPwd = userInfo.substr(pos + 1);

  return std::vector<std::string>{uName, uPwd};
}

std::string authUser(const std::string& message) {
  std::vector<std::string> userInfo = getInfo(message);

  std::string uName = userInfo[0];
  std::string uPwd = userInfo[1];
  
  auto checkingUser = userManager.login(uName, uPwd);

  if(checkingUser.getUserName() != "") {
    
    userLogin.setUserName(checkingUser.getUserName());
    userLogin.setUserPasswd(checkingUser.getUserPasswd());
    return "Welcome " + userLogin.getUserName() + "\n";
  }
  return "Invalid Credentials: User not Found\n";
}

std::string createUser(const std::string& message){

  std::vector<std::string> userInfo = getInfo(message);
  std::ostringstream result;

  std::string uName = userInfo[0];
  std::string uPwd = userInfo[1];

  auto userCreated = userManager.createUser(uName, uPwd);

  if(userCreated.getUserName() != "")
    return "User Created, Please Login.\n";
  else
    return "Username already exits, Sorry :(\n";
}

std::string logOut() {
  auto userLogout = userManager.logOut(userLogin.getUserName(), userLogin.getUserPasswd());

  if(userLogout.getUserName() != "") {
    userLogin.setUserName("");
    userLogin.setUserPasswd("");
    return "You are logged out\n";
  }else{
    return "Please login! \n";
  }
}*/



/* MOVE: Example ServerCommands usage code */

string exampleFunc1(const vector<string> &args) {
    string username = args[0];
    string password = args[1];
    return "Test output: User " + username + " " + password + " logged in!";
}

string exampleFunc2(const vector<string> &args) {
    return "Test output: Example User logged out!";
}

// Not a field
ServerCommands createTestCommands() {
    ServerCommands commands;
    std::string cmdName = "login";
    ServerCommands::function_ptr cmdFn = &exampleFunc1;
    int argCount = 2;
    commands.createNew(cmdName, cmdFn, argCount); // login
    commands.createNew("anything", &exampleFunc2, 0); //
    return commands;
}

/* MOVE */


// Users can type
//  login <arg> <arg>
//  anything
// Crashes if command does not created
std::string
processMessages(Server &server,
                const std::deque<Message> &incoming,
                bool &quit) {
<<<<<<< HEAD
  std::ostringstream result;
  for (auto& message : incoming) {
    if (message.text == "quit") {
      server.disconnect(message.connection);
    } else if (message.text == "shutdown") {
      std::cout << "Shutting down.\n";
      quit = true;
    } else {
      result << message.text;
      GameManager::getInstance()->extractCommands(message.text);
      result << message.connection.id << "> " << message.text << "\n";
    }
  }
  return result.str();
=======
    std::ostringstream result;
    ServerCommands test = createTestCommands();
    for (auto& message : incoming) {
        result << message.connection.id << " > ";
        result << test.process(std::move(message.text));
        result << std::endl;
    }
    return result.str();
>>>>>>> Server commands with any string name can be created and evaluated
}


std::deque<Message>
buildOutgoing(const std::string& log) {
  std::deque<Message> outgoing;
  for (auto client : clients) {
    outgoing.push_back({client, log});
  }
  return outgoing;
}


std::string
getHTTPMessage(const char* htmlLocation) {
  if (access(htmlLocation, R_OK ) != -1) {
    std::ifstream infile{htmlLocation};
    return std::string{std::istreambuf_iterator<char>(infile),
                       std::istreambuf_iterator<char>()};

  } else {
    std::cerr << "Unable to open HTML index file:\n"
              << htmlLocation << "\n";
    std::exit(-1);
  }
}


int
main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
              << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
    return 1;
  }

  bool done = false;
  unsigned short port = std::stoi(argv[1]);
  Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};


  while (!done) {
    try {
      server.update();
    } catch (std::exception& e) {
      std::cerr << "Exception from Server update:\n"
                << " " << e.what() << "\n\n";
      done = true;
    }

    auto incoming = server.receive();
    auto log      = processMessages(server, incoming, done);
    auto outgoing = buildOutgoing(log);
    server.send(outgoing);
    sleep(1);
  }

  return 0;
}

