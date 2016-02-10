set(TEST_CAMERA_FACTORY_SOURCES
    main.cxx
    testcameraFactory.cxx
    ../../cameraFactory/cameraFactory.cxx
    ../../cameraAdapter/cameraAdapter.cxx
)

add_executable(testcameraFactory ${TEST_CAMERA_FACTORY_SOURCES})

target_link_libraries(testcameraFactory
    gmock
    ${raspicam_LIBS}
)

include_directories(
    "../../lib/gtest/include"
    "../../lib/gmock/include"
    "../../cameraFactory/include"
    "../../cameraAdapter/include"
    "../../videoAdapter/include"
)

install(TARGETS testcameraFactory 
    DESTINATION ${HOST_MOUNTPOINT}${PI_TEST_INSTALL_PATH})
