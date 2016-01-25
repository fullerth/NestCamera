#include "cameraAdapter/cameraAdapter.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"
#include "raspicam/mocks/mockRaspiCam.h"
using ::testing::_;

TEST(cameraAdapter, hasGetVideoMethod) {
    CameraAdapter c = CameraAdapter();
    VideoAdapter v = c.getVideo();
}

TEST(cameraAdapter, getCameraCallsOpen) {
    raspicam::MockRaspiCam m;
    EXPECT_CALL(m, open(_)).Times(1);
    CameraAdapter c = CameraAdapter(&m);    
    c.getCamera();
}

//TODO: 
//TEST hasConfigureCameraMethod
