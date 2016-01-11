#include "gtest/gtest.h"
#include "cameraFactory/cameraFactory.h"
#include "cameraAdapter/cameraAdapter.h"

TEST(cameraFactory, hasGetCameraMethod) {
    CameraFactory f = CameraFactory();
    CameraAdapter c = f.getCamera();
} 

TEST(mockCameraFactory, exists) {
    MockCameraFactory m;
} 
