#include "cameraAdapter/cameraAdapter.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"

TEST(cameraAdapter, hasGetVideoMethod) {
    CameraAdapter c = CameraAdapter();
    VideoAdapter v = c.getVideo();
}

//TODO: 
//TEST hasConfigureCameraMethod
