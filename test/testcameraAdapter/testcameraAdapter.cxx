#include "cameraAdapter/cameraAdapter.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"
#include "raspicam/mocks/mockRaspiCam.h"
#include "testcameraAdapter/testcameraAdapter.h"

using ::testing::_;
using ::testing::Return;

namespace testcameraAdapter
{
    // getVideo
    TEST(cameraAdapter, getVideoMethodCallsConfigBeforeOpen) {
        CameraConfig cfg = CameraConfig();
        raspicam::MockRaspiCam m;
        ExpectationSet cfg_expects = addConfigureExpectations(&m, &cfg);
        EXPECT_CALL(m, open(_)).After(cfg_expects);
        CameraAdapter c = CameraAdapter(&m);
        VideoAdapter v = c.getVideo();
    }

    // getCamera
    TEST(cameraAdapter, openCameraCallsOpen) {
        raspicam::MockRaspiCam m;
        EXPECT_CALL(m, open(_)).Times(1);
        CameraAdapter c = CameraAdapter(&m);    
        c.openCamera();
    }

    TEST(cameraAdapter, openCameraCorrectlyReturnsValues) {
        raspicam::MockRaspiCam m;
        EXPECT_CALL(m, open(_)).WillOnce(Return(true)).WillOnce(Return(false));
        CameraAdapter c = CameraAdapter(&m);
        ASSERT_TRUE(c.openCamera());
        ASSERT_FALSE(c.openCamera());
    }

    //grab
    TEST(cameraAdapter, grabCameraCallsGrab) {
        raspicam::MockRaspiCam m;
        EXPECT_CALL(m, grab()).Times(1);
        CameraAdapter c = CameraAdapter(&m);
        c.grab();
    }

    //configureCamera
    TEST(cameraAdapter, configureCameraCallsSetters) {
        CameraConfig cfg = CameraConfig();
        raspicam::MockRaspiCam m;
        addConfigureExpectations(&m, &cfg);
        CameraAdapter c = CameraAdapter(&m);
        c.configureCamera(&cfg);
    }

    //Helper functions
    ExpectationSet addConfigureExpectations(raspicam::MockRaspiCam* m, CameraConfig* cfg)
    {
        ExpectationSet cfg_set;
        cfg_set += EXPECT_CALL(*m, setWidth(cfg->width)).Times(1);
        cfg_set += EXPECT_CALL(*m, setHeight(cfg->height)).Times(1);
        cfg_set += EXPECT_CALL(*m, setHorizontalFlip(cfg->hFlip)).Times(1);
        cfg_set += EXPECT_CALL(*m, setVerticalFlip(cfg->vFlip)).Times(1); 
        return cfg_set;
    }

}
