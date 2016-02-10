#include "cameraAdapter/cameraAdapter.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"
#include "raspicam/mockRaspiCam.h"
#include "testcameraAdapter/testcameraAdapter.h"

using ::testing::_;
using ::testing::Return;
using namespace std;

namespace testcameraAdapter
{

    // Default Constructor
    TEST(cameraAdapter, defaultConstructorCreatesRaspiCam) {
        CameraAdapter c = CameraAdapter();
        //Can't call open camera if m_cam is null
        c.openCamera();
    }

    // getVideo
    TEST(cameraAdapter, getVideoMethodCallsConfigBeforeOpen) {
        CameraConfig cfg = CameraConfig();
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        ExpectationSet cfg_expects = addConfigureExpectations(m, &cfg);
        EXPECT_CALL(*m, open(_)).After(cfg_expects);
        //grab expectations
        EXPECT_CALL(*m, grab()).Times(1);
        CameraAdapter c = CameraAdapter(m);
        VideoAdapter v = c.getVideo();
    }

    // getCamera
    TEST(cameraAdapter, openCameraCallsOpen) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, open(_)).Times(1);
        CameraAdapter c = CameraAdapter(m);    
        c.openCamera();
    }

    TEST(cameraAdapter, openCameraCorrectlyReturnsValues) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, open(_)).WillOnce(Return(true)).WillOnce(Return(false));
        CameraAdapter c = CameraAdapter(m);
        ASSERT_TRUE(c.openCamera());
        ASSERT_FALSE(c.openCamera());
    }

    //grab
    TEST(cameraAdapter, grabCallsParentGrab) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, grab()).Times(1);
        CameraAdapter c = CameraAdapter(m);
        c.grab();
    }

    //retrieve
    TEST(cameraAdapter, retrieveCallsParentRetrieve) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, retrieve(_,_)).Times(1);
        CameraAdapter c = CameraAdapter(m);
        //allocate memory
        unsigned char data[60000];
        c.retrieve(data);
    }

    //getImageTypeSize
    TEST(cameraAdapter, getImageSizeCallsParent) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)
                ).WillOnce(Return(20));
        CameraAdapter c = CameraAdapter(m);
        EXPECT_EQ(c.getImageSize(), 20);
    }

    //getWidth
    TEST(cameraAdapter, getWidthCallsParent) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, getWidth()).WillOnce(Return(20));
        CameraAdapter c = CameraAdapter(m);
        EXPECT_EQ(c.getWidth(), 20);
    }

    //getHeight
    TEST(cameraAdapter, getHeightCallsParent) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, getHeight()).WillOnce(Return(35));
        CameraAdapter c = CameraAdapter(m);
        EXPECT_EQ(c.getHeight(), 35);
    }

    //configureCamera
    TEST(cameraAdapter, configureCameraCallsSetters) {
        CameraConfig cfg = CameraConfig();
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        addConfigureExpectations(m, &cfg);
        CameraAdapter c = CameraAdapter(m);
        c.configureCamera(&cfg);
    }

    //Helper functions
    ExpectationSet addConfigureExpectations(
        std::shared_ptr<raspicam::MockRaspiCam> m, CameraConfig* cfg)
    {
        ExpectationSet cfg_set;
        cfg_set += EXPECT_CALL(*m, setWidth(cfg->width)).Times(1);
        cfg_set += EXPECT_CALL(*m, setHeight(cfg->height)).Times(1);
        cfg_set += EXPECT_CALL(*m, setHorizontalFlip(cfg->hFlip)).Times(1);
        cfg_set += EXPECT_CALL(*m, setVerticalFlip(cfg->vFlip)).Times(1); 
        return cfg_set;
    }

}
