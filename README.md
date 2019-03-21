# Faworki

### Quick Links
* Iteration
    * [Boards][boards] ~important
    * [Issues][issues] 
        * [Add][issues/new]
    * [Milestones][milestones]
    * [Labels][labels]
* [Wiki pages][wiki] ~wiki
* Branches
    * [_Master_](#master) 
    * [_Libraries_](#libraries)
    * [Graph][graph]
* Details
    * [Build & Run code](#run-chat-server-and-chat-client)
    * [Progress checklist][progress]
    * [Markdown][markdown]

> _Feb 16 - Mar 15_








<br />

# _Master_ 

### Pipeline

[![master-status]][commits/master] [![master-cover]][commits/master]

### Contribute
* [Update master branch][merge/new]
* [Contribution guide](CONTRIBUTING.md)





<br />

#  _Libraries_ 

### Pipeline

[![lib-status]][commits/libraries] [![lib-cover]][commits/libraries]

### Be up to date

* Clone _libraries_ branch

        git clone -b libraries https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019.git
        
* Follow [instuctions](#run-chat-server-and-chat-client) to test your code
* Commit compilable code
* Resolve known [compiler warnings](#warnings) ~warning
* View the [checklist](#progress)

> _Original __README.md__ renamed to __[index.md][network/index]__ and moved to [Network library index page][network]_






<br /><br />

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








<br /><br />

## Warnings

Warnings are removed from __README__.

> _See_ ~issue #17







<br />

## Progress

Progress is removed from __README.md__.

> _See [project wiki][progress]_ ~wiki










<!-- Links -->
[issues]: /../issues/
[issues/new]: /../issues/new/
[boards]: /../boards/
[milestones]: /../milestones/
[merge/new]: /../merge_requests/new/
[graph]: /../network/master
[labels]: /../labels/
[markdown]: https://csil-git1.cs.surrey.sfu.ca/help/user/markdown.md

[network]: https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/tree/master/lib/network
[network/index]: https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/tree/master/lib/network/index.md

[commits/master]: /../commits/master
[master-status]: https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/badges/master/pipeline.svg
[master-cover]: https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/badges/master/coverage.svg

[commits/libraries]: /../commits/libraries
[lib-status]: https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/badges/libraries/pipeline.svg
[lib-cover]: https://csil-git1.cs.surrey.sfu.ca/373-19-1-faworki/adventure2019/badges/libraries/coverage.svg

[wiki]: /../wikis/
[progress]: /../wikis/progress/
