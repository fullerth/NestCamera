#include <iostream>
#include <unistd.h>
#include "raspiCamera/raspiCamera.h"

int main(int argc, char **argv)
{
    RaspiCamera r;
    r.startVideo("foo", "bar");
    sleep(20);
    r.stopVideo();
    std::cout << "Hello World 2!\n";
    return 0;
}
