#ifndef __IMAGE_ADAPTER_H__
#define __IMAGE_ADAPTER_H__

#include <cstddef>
#include <ostream>
#include <memory>

class CameraAdapter;

class ImageAdapter {
    friend class CameraAdapter;
    public:
        ImageAdapter(size_t s);
        ~ImageAdapter();
        size_t getSize();
        void save(std::ostream &s);

    private:
        size_t m_size;
        unsigned char* m_data;
        unsigned char* m_write_ptr;
};

#endif
