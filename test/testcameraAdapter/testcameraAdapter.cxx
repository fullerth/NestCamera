#include "cameraAdapter/cameraAdapter.h"
#include "gtest/gtest.h"
#include "videoAdapter/videoAdapter.h"
#include "raspicam/mockRaspiCam.h"
#include "testcameraAdapter/testcameraAdapter.h"
#include "imageAdapter/imageAdapter.h"

using ::testing::_;
using ::testing::Return;
using ::testing::SetArrayArgument;
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
    TEST(getVideo, callsConfigBeforeOpen) {
        CameraConfig cfg = CameraConfig();
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        ExpectationSet cfg_expects = addConfigureExpectations(m, &cfg);
        EXPECT_CALL(*m, open(_)).After(cfg_expects);
        //grab expectations
        EXPECT_CALL(*m, grab()).Times(1);
        CameraAdapter c = CameraAdapter(m);
        std::shared_ptr<VideoAdapter> v = c.getVideo();
    }

    // getImage
    TEST(getImage, createsCorrectSizeImage) {
        CameraAdapter c = CameraAdapter();
        int expected_size = c.getWidth() * c.getHeight();
        std::shared_ptr<ImageAdapter> img = c.getImage();
        EXPECT_EQ(expected_size, img->getSize()) << "Width: " << c.getWidth() 
            << " Height: " << c.getHeight();
    }

    TEST(getImage, ImageAdapterContainsCorrectData) {
        std::shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        unsigned char imgData[4] = {10, 20, 30, 40};
        EXPECT_CALL(*m, retrieve(_,_)
                ).WillOnce(SetArrayArgument<0>(begin(imgData),end(imgData)));
        CameraAdapter c = CameraAdapter(m);
        std::shared_ptr<ImageAdapter> img = c.getImage(); 

    }

    // openCamera
    TEST(openCamera, callsRaspiCamOpen) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, open(_)).Times(1);
        CameraAdapter c = CameraAdapter(m);    
        c.openCamera();
    }

    TEST(openCamera, returnsCorrectValues) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, open(_)).WillOnce(Return(true)).WillOnce(Return(false));
        CameraAdapter c = CameraAdapter(m);
        ASSERT_TRUE(c.openCamera());
        ASSERT_FALSE(c.openCamera());
    }

    //grab
    TEST(grab, callsRaspiCamGrab) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, grab()).Times(1);
        CameraAdapter c = CameraAdapter(m);
        c.grab();
    }

    //retrieve
    TEST(retrieve, callsRaspiCamRetrieve) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, retrieve(_,_)).Times(1);
        CameraAdapter c = CameraAdapter(m);
        //allocate memory
        unsigned char data[60000];
        c.retrieve(data);
    }

    //getImageSize
    TEST(getImageSize, callsRaspiCamGetImageTypeSize) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)
                ).WillOnce(Return(20));
        CameraAdapter c = CameraAdapter(m);
        EXPECT_EQ(c.getImageSize(), 20);
    }

    //getWidth
    TEST(getWidth, callsParent) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, getWidth()).WillOnce(Return(20));
        CameraAdapter c = CameraAdapter(m);
        EXPECT_EQ(c.getWidth(), 20);
    }

    //getHeight
    TEST(getHeight, callsParent) {
        shared_ptr<raspicam::MockRaspiCam> m(new raspicam::MockRaspiCam);
        EXPECT_CALL(*m, getHeight()).WillOnce(Return(35));
        CameraAdapter c = CameraAdapter(m);
        EXPECT_EQ(c.getHeight(), 35);
    }

    //configureCamera
    TEST(configureCamera, callsSetters) {
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
