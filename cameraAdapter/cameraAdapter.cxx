#include "cameraAdapter/cameraAdapter.h"

/**********************************************************
 * Camera Adapter Functions                               *
 **********************************************************/
CameraAdapter::CameraAdapter() {
    m_cam = std::shared_ptr<raspicam::RaspiCam>(new raspicam::RaspiCam);
}

CameraAdapter::CameraAdapter(std::shared_ptr<raspicam::RaspiCam> cam) : m_cam(cam) {
}

CameraAdapter::~CameraAdapter() {
}

std::shared_ptr<VideoAdapter> CameraAdapter::getVideo() {
    this->configureCamera(&m_cfg);
    m_cam->open();
    m_cam->grab();

}

std::shared_ptr<ImageAdapter> CameraAdapter::getImage() {
    return std::shared_ptr<ImageAdapter>(new ImageAdapter(25));
}

bool CameraAdapter::openCamera() {
    return(m_cam->open());
}

bool CameraAdapter::grab() {
    m_cam->grab();
}    

size_t CameraAdapter::getImageSize() const {
    return(m_cam->getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));
}

void CameraAdapter::retrieve(unsigned char *data) {
    m_cam->retrieve(data, raspicam::RASPICAM_FORMAT_RGB);
    
}

void CameraAdapter::configureCamera(CameraConfig* cfg) {
    m_cam->setWidth(cfg->width);
    m_cam->setHeight(cfg->height);
    m_cam->setHorizontalFlip(cfg->hFlip);
    m_cam->setVerticalFlip(cfg->vFlip);

}

unsigned int CameraAdapter::getWidth() {
    return (m_cam->getWidth());
}

unsigned int CameraAdapter::getHeight() {
    return (m_cam->getHeight());
}
