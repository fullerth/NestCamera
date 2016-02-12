set(TEST_IMAGE_ADAPTER_SOURCES
    main.cxx
    testimageAdapter.cxx
    ../../imageAdapter/imageAdapter.cxx
)

add_executable(testimageAdapter ${TEST_IMAGE_ADAPTER_SOURCES})

## Libraries
target_link_libraries(testimageAdapter
    gmock
)

include_directories(
    "../../lib/gtest/include"
    "../../lib/gmock/include"
    "../../imageAdapter/include"
    "include"
)

install(TARGETS testimageAdapter 
    DESTINATION ${HOST_MOUNTPOINT}${PI_TEST_INSTALL_PATH})


