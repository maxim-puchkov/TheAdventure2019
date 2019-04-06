
#ifndef WEBSOCKETNETWORKING_LOCATIONCOORDINATES_H
#define WEBSOCKETNETWORKING_LOCATIONCOORDINATES_H

#include "Internationalization.h"

using internationalization::Internationalization;
#include <string>

struct LocationCoordinates
{
    //int area;
    std::string area = "";
    int room;
};

#endif //WEBSOCKETNETWORKING_LOCATIONCOORDINATES_H
