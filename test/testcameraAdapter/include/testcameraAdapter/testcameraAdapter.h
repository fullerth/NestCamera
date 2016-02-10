#include <memory>

#ifndef __testCameraAdapter_H__
#define __testCameraAdapter_H__

namespace testcameraAdapter
{
    using ::testing::ExpectationSet;
    ExpectationSet addConfigureExpectations(std::shared_ptr<raspicam::MockRaspiCam> m, CameraConfig* cfg);

}

#endif
