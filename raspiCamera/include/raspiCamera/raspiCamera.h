#include "unistd.h"

class RaspiCameraInterface
{
    public:
        virtual void startVideo(char* filename, char* options);
        virtual void stopVideo();
};

class RaspiCamera : RaspiCameraInterface
{
    public:
        void startVideo(char* filename, char* options);
        void stopVideo();
    private:
        pid_t* m_pid;
};

