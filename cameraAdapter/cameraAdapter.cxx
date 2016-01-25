#include "cameraAdapter/cameraAdapter.h"

CameraAdapter::CameraAdapter() {

}

CameraAdapter::CameraAdapter(raspicam::RaspiCam* cam) : m_cam(cam) {
}

VideoAdapter CameraAdapter::getVideo() {

}

void CameraAdapter::getCamera() {
    m_cam->open();
}

