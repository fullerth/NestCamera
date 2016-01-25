#include "videoAdapter/videoAdapter.h"
#include "raspicam/raspicam.h"

#ifndef __NEST_CAMERA_CAMERA_ADAPTER__
#define __NEST_CAMERA_CAMERA_ADAPTER__

class CameraAdapter {
    public: 
        CameraAdapter();
        CameraAdapter(raspicam::RaspiCam* cam);
        VideoAdapter getVideo();
        void getCamera();

    private:
        raspicam::RaspiCam* m_cam;
};

#endif //__NEST_CAMERA_CAMERA_ADAPTER__
