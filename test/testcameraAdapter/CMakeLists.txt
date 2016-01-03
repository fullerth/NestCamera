set(TEST_CAMERA_ADAPTER_SOURCES
    main.cxx
    testcameraAdapter.cxx
)

add_executable(testcameraAdapter ${TEST_CAMERA_ADAPTER_SOURCES})

target_link_libraries(testcameraAdapter
    gmock
)

include_directories(
    "../../lib/gtest/include"
    "../../lib/gmock/include"
    "../../cameraAdapter/include"
)

install(TARGETS testcameraAdapter DESTINATION bin)
