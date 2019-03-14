#ifndef ADVENTURE2019_TIMESTAMP_H
#define ADVENTURE2019_TIMESTAMP_H

#include <time.h>
#include <iostream>

static unsigned long getTimeStamp(){
    auto currentTime = clock();

    std::cerr << "timestamp created: " << static_cast<unsigned long>(currentTime) << "\n";

    return static_cast<unsigned long>(currentTime);
}

#endif
