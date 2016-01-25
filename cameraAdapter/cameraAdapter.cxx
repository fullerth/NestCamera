#include "cameraAdapter/cameraAdapter.h"

CameraAdapter::CameraAdapter() {

}

CameraAdapter::CameraAdapter(raspicam::RaspiCam* cam) : m_cam(cam) {
}

VideoAdapter CameraAdapter::getVideo() {

}

bool CameraAdapter::getCamera() {
    return(m_cam->open());
}

