/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unistd.h>

#include "ChatWindow.h"
#include "Client.h"


int
main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: \n  " << argv[0] << " <ip address> <port>\n"
        << "  e.g. " << argv[0] << " localhost 4002\n";
        return 1;
    }
}
