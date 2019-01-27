/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Server.h"
#include "User.h"
#include "GameManager.h"

// #include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>

#include <stdint.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using networking::Server;
using networking::Connection;
using networking::Message;

std::vector<Connection> clients;
GameManager gm;

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


std::unique_ptr<std::unordered_map<std::string, std::string>>
processMessages(Server &server,
                const std::deque<Message> &incoming,
                bool &quit) {

  auto result = std::make_unique<std::unordered_map<std::string, std::string>>();
  for (auto& message : incoming) {

    if (message.text == "quit") {
      server.disconnect(message.connection);
    } else if (message.text == "shutdown") {
      std::cout << "Shutting down.\n";
      quit = true;
    } else {
      std::string connectionID = std::to_string(message.connection.id);
      std::string serverAnswer = connectionID + "> " + message.text + "\n";
      serverAnswer.append(gm.extractCommands(connectionID, message.text));

      std::pair<std::string, std::string> answerPair (connectionID, serverAnswer);
      result->insert(answerPair);
    }
  }
  return result;
}


std::deque<Message>
buildOutgoing(std::unique_ptr<std::unordered_map<std::string, std::string>> logs) {
  std::deque<Message> outgoing;
  for (auto client : clients) {
    auto found = logs->find(std::to_string(client.id));
    if(found != logs->end())
      outgoing.push_back({client, found->second});
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


std::unique_ptr<std::unordered_map<std::string, std::string>>
includeHeartbeatMessages(std::unique_ptr<std::unordered_map<std::string, std::string>> tableA, std::unique_ptr<std::unordered_map<std::string, std::string>> tableB) {
  // x is each key in the tableB
  for (auto x : *tableB) {
    // if key exists in tableA
    if ((*tableA).count(x.first) >= 0) {  
      (*tableA).insert(x.first, ((*tableA).at(x.first)).append(x.second));
    }
    else {
      (*tableA).insert(x.first, x.second);
    }
  }
  return tableA;
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
    auto logs      = processMessages(server, incoming, done);
    auto outgoing = buildOutgoing(std::move(logs));
    server.send(outgoing);
    sleep(1);
  }

  return 0;
}

