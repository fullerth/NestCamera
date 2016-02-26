#include <cstddef>
#include <ostream>
#include <memory>

#ifndef __IMAGE_ADAPTER_H__
#define __IMAGE_ADAPTER_H__

class ImageAdapter {
    public:
        ImageAdapter(size_t s);
        ~ImageAdapter();
        size_t getSize();
        void save(std::ostream &s);

    private:
        size_t m_size;
        char* m_data;
        char* m_write_ptr;
};

#endif
