set(TEST_FOO_SOURCES
    main.cxx
    testfoo.cxx
)

add_executable(testfoo ${TEST_FOO_SOURCES})

target_link_libraries(testfoo
    libfoo
    gtest
)

include_directories(
    "../../lib/gtest/include/"
    "../../libfoo/"
)

install(TARGETS testfoo DESTINATION bin)
