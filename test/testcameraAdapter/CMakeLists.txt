set(TEST_CAMERA_ADAPTER_SOURCES
    main.cxx
    testcameraAdapter.cxx
    ../../cameraAdapter/cameraAdapter.cxx
    ../../imageAdapter/imageAdapter.cxx
)

add_executable(testcameraAdapter ${TEST_CAMERA_ADAPTER_SOURCES})

## Libraries
target_link_libraries(testcameraAdapter
    gmock
    ${raspicam_LIBS}
)

include_directories(
    "../../lib/gtest/include"
    "../../lib/gmock/include"
    "../../cameraAdapter/include"
    "../../videoAdapter/include"
    "../../imageAdapter/include"
    "include"
)

install(TARGETS testcameraAdapter 
    DESTINATION ${HOST_MOUNTPOINT}${PI_TEST_INSTALL_PATH})


