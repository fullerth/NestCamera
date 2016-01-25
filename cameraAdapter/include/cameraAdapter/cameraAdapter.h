#include "videoAdapter/videoAdapter.h"
#include "raspicam/raspicam.h"

#ifndef __NEST_CAMERA_CAMERA_ADAPTER__
#define __NEST_CAMERA_CAMERA_ADAPTER__

struct CameraConfig {
    int width;
    int height;
    bool hFlip;
    bool vFlip;
};

class CameraAdapter {
    public: 
        CameraAdapter();
        CameraAdapter(raspicam::RaspiCam* cam);
        VideoAdapter getVideo();
        bool getCamera();
        void configureCamera(CameraConfig* cfg);

    private:
        raspicam::RaspiCam* m_cam;
};

#endif //__NEST_CAMERA_CAMERA_ADAPTER__
