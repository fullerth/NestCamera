#include "raspiCamera/raspiCamera.h"

void RaspiCamera::startVideo(std::string filename, std::string options)
{
    if((m_pid = fork()) == 0)
    {
        char** cmd;
        int count = 0;


        typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
        tokenizer tok{options};
        for(tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
        {
            count++;
            std::cout << *it << '\n';
        } 

        std::cout << "Count: " << count << std::endl;

    }
    else
    {
        std::cout << "startVideo\n";
    }
}

void RaspiCamera::stopVideo()
{
    std::cout << "stopVideo\n";
}
