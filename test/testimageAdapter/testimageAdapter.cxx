#include "imageAdapter/imageAdapter.h"
#include "gmock/gmock.h"

TEST(imageAdapter, constructorTakesSize) {
    size_t size = 50;
    ImageAdapter img = ImageAdapter(size);
    EXPECT_EQ(img.getSize(), size);
}

TEST(imageAdapter, saveMethodExists) {
    ImageAdapter img = ImageAdapter(25);
    img.save();

}
