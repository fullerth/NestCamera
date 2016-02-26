#include "imageAdapter/imageAdapter.h"

ImageAdapter::ImageAdapter(size_t s) : m_size(s), m_data(new unsigned char[s]), 
    m_write_ptr(m_data){
}

ImageAdapter::~ImageAdapter() {
    delete[] m_data;
}

size_t ImageAdapter::getSize() {
    return m_size;
}

void ImageAdapter::save(std::ostream &s) {
    s << "P6\n1280 960 255\n";
}

