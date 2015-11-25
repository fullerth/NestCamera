## CMakeLists.txt
cmake_minimum_required(VERSION 2.8.7)
project(NestCamera)

include(CTest)

add_subdirectory(main)

add_subdirectory(test/testfoo)
add_test(NAME AllTestsInFoo COMMAND testfoo)
add_subdirectory(libfoo)

add_subdirectory(raspiCamera)

add_subdirectory(lib/gtest)

include_directories(
    "lib/gmock/include"
    "raspiCamera/include"
)

set(MAIN_SOURCES
    main/main.cxx)

add_executable(NestCamera
    ${MAIN_SOURCES}
	       )


