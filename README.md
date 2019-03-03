# Iteration 2 overview

* [_Libraries_ branch](#libraries)

    * [Build & Run code](#run-chat-server-and-chat-client)

* [Compiler warnings](#warnings)

* [Progress checklist](#progress)


> _Feb 16 - Mar 15_








&nbsp;
#  _Libraries_ 

### Be up to date

* Clone _libraries_ branch

        git clone -b libraries https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019.git

* Follow [instuctions](#run-chat-server-and-chat-client) to test your code

* Commit compilable code

* Resolve known [compiler warnings](#warnings)

* View the [checklist](#progress)

> Original [README.md](https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/tree/master/lib/network)








&nbsp;
# Run chat server and chat client

## Building with CMake

1. Clone the repository.

        git clone https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019.git

2. Create a new directory for building.

        mkdir build

3. Change into the new directory.

        cd build

4. Run CMake with the path to the source.

        cmake ../adventure2019/

5. Run make inside the build directory:

        make

This produces `chatserver` and `chatclient` tools called `bin/chatserver` and
`bin/chatclient` respectively. The library for single threaded clients and
servers is built in `lib/`.

Note, building with a tool like ninja can be done by adding `-G Ninja` to
the cmake invocation and running `ninja` instead of `make`.


### Dependencies

This project requires:

1. C++17 or newer
2. Boost >= 1.66
3. CMake >= 3.12
4. NCurses (only tested with 6.1)



## Running

First run the chat server on an unused port of the server machine. The server
also takes an HTML file that it will server to standard http requests for
`index.html`.

    bin/chatserver 4000 ../adventure2019/webchat.html

In separate terminals, run multiple instances of the chat client using:

    bin/chatclient localhost 4000

This will connect to the given port (4000 in this case) of the local machine.
Connecting to a remote machine can be done by explicitly using the remote
machine's IP address instead of `localhost`. Inside the chat client, you can
enter commands or chat with other clients by typing text and hitting the
ENTER key. You can disconnect from the server by typing `quit`. You can shut
down the server and disconnect all clients by typing `shutdown`. Typing
anything else will send a chat message to other clients.

A browser based interface can be accessed by opening the URL
`http://localhost:4000/index.html`. The server will respond with the
specified web page above. By clicking `Connect`, the page gains access to
chat on the server via web sockets in browsers that support web sockets.








&nbsp;
# Warnings

### Debug
**4** compiler warnings are generated:

* JsonParser.cpp:33:12: 

    Address of stack memory associated with local variable `char_filePath` returned 
        
        [-Wreturn-stack-address]
        return char_filePath;
        ^~~~~~~~~~~~~
        
* OnlineUserManager.cpp:103:12: 


    Moving a local object in a return statement prevents copy elision
        
        [-Wpessimizing-move]
        return std::move(messageList);
               ^
                   
    Remove ```std::move call``` here
    
        return std::move(messageList);
               ^~~~~~~~~~           ~

* OnlineUserManager.cpp:140:12:

    Moving a local object in a return statement prevents copy elision
        
        [-Wpessimizing-move]
        return std::move(commandList);
               ^

    Remove ```std::move call``` here
        
        return std::move(commandList);
               ^~~~~~~~~~           ~
               
* GameManager.cpp:315:12:

    Moving a local object in a return statement prevents copy elision
        
        [-Wpessimizing-move]
        return std::move(map);
               ^
               
    Remove ```std::move call``` here
        
        return std::move(map);
               ^~~~~~~~~~   ~








&nbsp;
# Progress

### Interaction

* [ ] A user must be able to interact with the world by typing commands into a chat-like interface.
* [ ] Commands from all users are collected and buffered (to a bounded length) by the server.
* [ ] At fixed intervals or heartbeats, the server will take the first command each active user's buffer and execute it.
* [ ] The order between different user's commands is nondeterministic.
* [ ] Possible messages to users are buffered and then sent back to users once all updates have completed.
* [ ] Performance of the overall system should scale with impercetible delay for a reasonable number of users.




### Users, Avatars, Characters, and Worlds

* [ ] A user connecting to the system will either create a new account or log into an existing account with a username and password.
* [ ] A user experiences the simulated world through the eyes of their avatar. This is a character representation of the user in the world.
* [ ] The first time a users logs in, they will go through a process of creating and customizing their avatar.
* [ ] An avatar will always exist at a particular location in the world called a room.
* [ ] A room has at least a name and a description. It can contain characters, objects, more detailed descriptions, and other things of interest.
* [ ] Rooms can be connected to other rooms either by cardinal and ordinal directions, up and down directions, and custom room specific directions.
* [ ] The connections between rooms via the directions can be arbitrary. They need not correspond to a Euclidean spatial model or be bidirectional.
* [ ] The world can be divided into collections of rooms called areas.
* [ ] Characters need not only be users. There may be non-user characters in the world. These may be interacted with in a variety of ways.
* [ ] Every so often (configurably), an area will reset. This will perform some basic maintenance in order to make sure that the world continues to be usable by additional users.
* [ ] Characters can have quantified and boolean attributes that will determine how they interact with the world.
* [ ] Characters can have an inventory of objects.
* [ ] Characters can wear appropriate objects like clothing.




### Communication

* [ ] A character can communicate with other users in a room by saying something. For instance, say Howdy! will display a message to all other characters in the room containing <username> says "Howdy!".
* [ ] A character can yell, which will be loud enough to be heard in adjacent rooms.
* [ ] A character can tell another character something, which can be heard by only the other user.




### Movement and World Interaction

* [ ] A characters can go in any direction that is valid in a room. Some conditions may make going in a direction fail.
* [ ] As shorthand for going in a cardinal, ordinal, or vertical direction, the direction name itself can be used as a command: north, south, east, west, northeast, southeast, northwest, southwest, up, down.
* [ ] A character may look at or examine other characters or items in the room.
* [ ] looking without an argument will look at the room itself and present the name and description of the room as well as a short description of the characters, objects, and cardinal/ordinal/vertical exits within the room.
* [ ] A room may have special keywords that when looked at provide deeper description.
* [ ] A character may try to get or take an object in the current room or from within a container object in the current room.




### Objects and Inventories

* [ ] A character may have an inventory of objects.
* [ ] Some of these objects may themselves be containers containing other objects.
* [ ] A character may put an object from their inventory into a container.
* [ ] A character may drop an object into their current room.
* [ ] A character may give an object to another character in the room.
* [ ] Wearable objects in the inventory can be worn using wear and removed to the inventory using remove.
* [ ] Worn objects may themselves have attributes that affect a character.




### Combat

* [ ] Users should be able to start fights with non-user characters by attacking them or trying to kill them.
* [ ] Upon doing so, the user enters a combat state that only ends when one of the participants loses or flees to a random neighboring * [ ] room.
* [ ] While in the combat state, a round of combat will run once every configurable number of heartbeats.
* [ ] In a single round of combat, both participants do a calculated amount of damage to each other.
* [ ] Attempts to leave the room or escape combat other than fleeing fail.




### World Builders

* [ ] Some users should be authorized to participate in building the world using special world building commands.
* [ ] This includes designing, creating, and modifying areas, rooms, non-user characters, and objects.




### Importing Data

* [ ] You should be able to import areas of the game from provided JSON formatted files.
* [ ] The spellings of commands should be configurable and easily internationalized.
* [ ] Global settings for the game should be configurable via a single JSON configuration file.
 
 


### Minigames

* [ ] You should support at least one minigame that can be played by users in the same room. Such example minigames are:
    * Multiple choice quizzes.
    * Bluff based question/answer games.
    * Hangman style question answer games.
    * Role based social deduction games.
* [ ] Players in the same room can join a minigame.
* [ ] Rounds of the minigame may span multiple heartbeats.
* [ ] Commands not used for movement or combat will still work during the minigames.
* [ ] Minigames may yield room specific commands.




### Roles and Rights

* [ ] Different users may have different rights that can be assigned or revoked, e.g. world building or minigame starting.
* [ ] Care should be taken to ensure that users without those rights cannot take those actions.
* [ ] Policies specifying who is able to do what should be flexible.




### Extras

* [ ] Other possible features that may be added include but are not limited to:
    * Crafting
    * Questing
    * Scripting
    * Twitch integration




### ...
* [ ] .........





