#include "cameraAdapter/cameraAdapter.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"
#include "raspicam/mocks/mockRaspiCam.h"
using ::testing::_;
using ::testing::Return;

// getVideo
TEST(cameraAdapter, hasGetVideoMethod) {
    CameraAdapter c = CameraAdapter();
    VideoAdapter v = c.getVideo();
}

// getCamera
TEST(cameraAdapter, getCameraCallsOpen) {
    raspicam::MockRaspiCam m;
    EXPECT_CALL(m, open(_)).Times(1);
    CameraAdapter c = CameraAdapter(&m);    
    c.getCamera();
}

TEST(cameraAdapter, getCameraCorrectlyReturnsValues) {
    raspicam::MockRaspiCam m;
    EXPECT_CALL(m, open(_)).WillOnce(Return(true)).WillOnce(Return(false));
    CameraAdapter c = CameraAdapter(&m);
    ASSERT_TRUE(c.getCamera());
    ASSERT_FALSE(c.getCamera());
}

//configureCamera
TEST(cameraAdapter, configureCameraCallsSetters) {
    CameraConfig cfg = {.width=10, .height=20, .hFlip=true, .vFlip=false};
    raspicam::MockRaspiCam m;
    EXPECT_CALL(m, setWidth(cfg.width)).Times(1);
    EXPECT_CALL(m, setHeight(cfg.height)).Times(1);
    EXPECT_CALL(m, setHorizontalFlip(cfg.hFlip)).Times(1);
    EXPECT_CALL(m, setVerticalFlip(cfg.vFlip)).Times(1); 
    CameraAdapter c = CameraAdapter(&m);
    c.configureCamera(&cfg);
}

//TODO: 
//TEST hasConfigureCameraMethod
