#include "cameraAdapter/cameraAdapter.h"

#ifndef __NEST_CAMERA_CAMERA_FACTORY__
#define __NEST_CAMERA_CAMERA_FACTORY__

class CameraFactory {
    public:
        CameraAdapter getCamera(); 
};

class MockCameraFactory : public CameraFactory {

};

#endif //__NEST_CAMERA_CAMERA_FACTORY__
