#include <stddef.h>

#ifndef __IMAGE_ADAPTER_H__
#define __IMAGE_ADAPTER_H__

class ImageAdapter {
    public:
        ImageAdapter(size_t s);
        size_t getSize();

    private:
        size_t m_size;
};

#endif
