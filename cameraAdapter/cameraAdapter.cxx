#include "cameraAdapter/cameraAdapter.h"

/**********************************************************
 * Camera Adapter Functions                               *
 **********************************************************/
CameraAdapter::CameraAdapter() {

}

CameraAdapter::CameraAdapter(raspicam::RaspiCam* cam) : m_cam(cam) {
}

VideoAdapter CameraAdapter::getVideo() {
    this->configureCamera(&m_cfg);
    m_cam->open();

}

bool CameraAdapter::openCamera() {
    return(m_cam->open());
}

void CameraAdapter::configureCamera(CameraConfig* cfg) {
    m_cam->setWidth(cfg->width);
    m_cam->setHeight(cfg->height);
    m_cam->setHorizontalFlip(cfg->hFlip);
    m_cam->setVerticalFlip(cfg->vFlip);

}

