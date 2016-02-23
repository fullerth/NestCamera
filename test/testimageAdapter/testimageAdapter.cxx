#include "testimageAdapter/testimageAdapter.h"

TEST(imageAdapter, constructorTakesSize) {
    size_t size = 50;
    ImageAdapter img = ImageAdapter(size);
    EXPECT_EQ(img.getSize(), size);
}

TEST(imageAdapter, saveMethodExists) {
    std::shared_ptr<MockFileStream> outFile(new MockFileStream());
    ImageAdapter img = ImageAdapter(25);
    img.save(outFile);
}
