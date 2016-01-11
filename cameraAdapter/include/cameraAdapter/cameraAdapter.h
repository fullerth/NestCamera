#include "videoAdapter/videoAdapter.h"

#ifndef __NEST_CAMERA_CAMERA_ADAPTER__
#define __NEST_CAMERA_CAMERA_ADAPTER__

class RaspicamFactory {

};

class MockRaspicamFactory : public RaspicamFactory {

};

class CameraAdapter {
    public: 
        CameraAdapter();
        CameraAdapter(RaspicamFactory);
        VideoAdapter getVideo();

};

#endif //__NEST_CAMERA_CAMERA_ADAPTER__
