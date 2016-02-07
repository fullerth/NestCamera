set(TEST_TOUCHSCREEN_ADAPTER_SOURCES
    main.cxx
    testtouchscreenAdapter.cxx
)

add_executable(testtouchscreenAdapter ${TEST_TOUCHSCREEN_ADAPTER_SOURCES})

## Libraries
target_link_libraries(testtouchscreenAdapter
    gmock
)

include_directories(
    "../../lib/gtest/include"
    "../../lib/gmock/include"
    "../../touchscreenAdapter/include"
)

install(TARGETS testtouchscreenAdapter 
    DESTINATION ${HOST_MOUNTPOINT}${PI_TEST_INSTALL_PATH})


