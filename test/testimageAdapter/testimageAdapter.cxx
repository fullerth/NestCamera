#include "testimageAdapter/testimageAdapter.h"

TEST(imageAdapter, constructorTakesSize) {
    size_t size = 50;
    ImageAdapter img = ImageAdapter(size);
    EXPECT_EQ(img.getSize(), size);
}

TEST(imageAdapter, saveMethodWritesHeader) {
    std::ostringstream s;
    ImageAdapter img = ImageAdapter(1);
    img.save(s);
    EXPECT_EQ("P6\n1280 960 255\n", s.str());
}
