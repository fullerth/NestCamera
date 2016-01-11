#include "cameraAdapter/cameraAdapter.h"
#include "cameraFactory/cameraFactory.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"

TEST(cameraAdapter, takesCameraFactoryInConstructor) {
    RaspicamFactory f = MockRaspicamFactory();
    CameraAdapter c = CameraAdapter(f);
}

TEST(cameraAdapter, hasGetVideoMethod) {
    RaspicamFactory f = MockRaspicamFactory();
    CameraAdapter c = CameraAdapter(f);
    VideoAdapter v = c.getVideo();
}

//TODO: 
//TEST hasConfigureCameraMethod
