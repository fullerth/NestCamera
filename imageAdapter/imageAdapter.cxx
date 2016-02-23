#include "imageAdapter/imageAdapter.h"

ImageAdapter::ImageAdapter(size_t s) : m_size(s) {

}

size_t ImageAdapter::getSize() {
    return m_size;
}

void ImageAdapter::save(std::ostream &s) {
    s << "25";
}
