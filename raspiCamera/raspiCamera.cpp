#include "raspiCamera/raspiCamera.h"

void RaspiCamera::startVideo(std::string filename, std::string options)
{
    std::string cmd = options;

    cmd.insert(0, "raspivid ");
    cmd.append(" -n -t 10 -s -o ");
    cmd.append(filename);

    std::cout << cmd << '\n';

    if((m_pid = fork()) == 0)
    {
        execl("/bin/sh", "/bin/sh", "-c", cmd.c_str());
    }
    else
    {
        std::cout << "startVideo\n";
    }
}

void RaspiCamera::stopVideo()
{
    if(m_pid)
    {
        kill(m_pid, 10);
    }
}
