#ifndef ADVENTURE2019_TIMESTAMP_H
#define ADVENTURE2019_TIMESTAMP_H

#include <time.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std::chrono;

static unsigned long long getTimeStamp(){
    unsigned long long ms =
        std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();

    //std::cout << ms << "\n";
    return ms;
}

#endif
