#include <memory>
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
        CameraAdapter(std::shared_ptr<raspicam::RaspiCam> cam);
        ~CameraAdapter();
        VideoAdapter getVideo();
        bool openCamera();
        bool grab();
        size_t getImageSize() const;
        void retrieve ( unsigned char *data);
        void configureCamera(CameraConfig* cfg);
        unsigned int getWidth();
        unsigned int getHeight();

    private:
        std::shared_ptr<raspicam::RaspiCam> m_cam;
        CameraConfig m_cfg = CameraConfig();
};

#endif //__NEST_CAMERA_CAMERA_ADAPTER__
