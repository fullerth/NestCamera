set(TEST_VIDEO_ADAPTER_SOURCES
    main.cxx
)

add_executable(testvideoAdapter ${TEST_VIDEO_ADAPTER_SOURCES})

target_link_libraries(testvideoAdapter
    gmock
)

include_directories(
    "../../lib/gtest/include"
    "../../lib/gmock/include"
    "../../videoAdapter/include"
)

install(TARGETS testvideoAdapter DESTINATION bin)
