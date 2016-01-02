#include "gtest/gtest.h"
#include "nestcamera/cameraFactory.h"
#include "nestcamera/cameraAdapter.h"

class MockCameraAdapter : public CameraAdapter {

};

TEST(cameraFactory, hasGetCameraMethod) {
    CameraFactory f = CameraFactory();
    CameraAdapter c = f.getCamera();
    EXPECT_EQ(0, 1) << "Finish the test";
} 

