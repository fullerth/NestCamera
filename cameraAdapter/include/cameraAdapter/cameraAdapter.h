#include "videoAdapter/videoAdapter.h"
#include "raspicam/raspicam.h"

#ifndef __NEST_CAMERA_CAMERA_ADAPTER__
#define __NEST_CAMERA_CAMERA_ADAPTER__

struct CameraConfig {
    int width = 800;
    int height = 600;
    bool hFlip = true;
    bool vFlip = false;
};

class CameraAdapter {
    public: 
        CameraAdapter();
        CameraAdapter(raspicam::RaspiCam* cam);
        VideoAdapter getVideo();
        bool openCamera();
        bool grab();
        void configureCamera(CameraConfig* cfg);

    private:
        raspicam::RaspiCam* m_cam;
        CameraConfig m_cfg = CameraConfig();
};

#endif //__NEST_CAMERA_CAMERA_ADAPTER__
