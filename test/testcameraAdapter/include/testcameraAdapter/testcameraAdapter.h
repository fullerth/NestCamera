#ifndef __testCameraAdapter_H__
#define __testCameraAdapter_H__

namespace testcameraAdapter
{
    using ::testing::ExpectationSet;
    ExpectationSet addConfigureExpectations(raspicam::MockRaspiCam* m, CameraConfig* cfg);

}

#endif
