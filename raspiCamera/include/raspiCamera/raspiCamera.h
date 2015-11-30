#ifndef __raspiCamera_h__
#define __raspiCamera_h__

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <signal.h>
#include <boost/tokenizer.hpp>

class IRaspiCamera
{
    public:
        virtual void startVideo(std::string filename, std::string options) = 0;
        virtual void stopVideo() = 0;
};

class RaspiCamera : public IRaspiCamera
{
    public:
        void startVideo(std::string filename, std::string options);
        void stopVideo();
    private:
        pid_t m_pid;
};

#endif //__raspiCamera_h__
