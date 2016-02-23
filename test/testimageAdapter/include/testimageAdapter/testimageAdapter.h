#include <fstream>
#include <memory>
#include "imageAdapter/imageAdapter.h"
#include "gmock/gmock.h"

class MockFileStream : public std::ofstream {
};
