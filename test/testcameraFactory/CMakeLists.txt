set(TEST_CAMERA_FACTORY_SOURCES
    main.cxx
    testcameraFactory.cxx
)

add_executable(testcameraFactory ${TEST_CAMERA_FACTORY_SOURCES})

target_link_libraries(testcameraFactory
    gmock
)

include_directories(
    "../../lib/gtest/include/"
    "../../lib/gmock/include/"
)

install(TARGETS testcameraFactory DESTINATION bin)
