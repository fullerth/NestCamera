#include "gtest/gtest.h"
#include "cameraFactory/cameraFactory.h"
#include "nestcamera/cameraAdapter.h"

TEST(cameraFactory, hasGetCameraMethod) {
    CameraFactory f = CameraFactory();
    CameraAdapter c = f.getCamera();
} 

