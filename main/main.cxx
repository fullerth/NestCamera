#include <iostream>
#include <unistd.h>
#include "raspiCamera/raspiCamera.h"

int main(int argc, char **argv)
{
    RaspiCamera r;
    r.startVideo("foo", "");
    std::cout << "Video Recording, press any key to end\n";
    std::cin.ignore();
    std::cout << "Video Recording Stopping\n";
    r.stopVideo();
    std::cout << "Video Recording Stopped\n";
    return 0;
}
