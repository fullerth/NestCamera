## CMakeLists.txt
cmake_minimum_required(VERSION 2.8.7)
project(NestCamera)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/lib/cmake/)

## Libraries
find_package(raspicam REQUIRED)

## Project Configuration
add_definitions(-std=c++11)
add_definitions(-gdwarf-3)
include(CTest)

## Directories to add to build
add_subdirectory(main)

add_subdirectory(test/testfoo)
add_test(NAME AllTestsInFoo COMMAND testfoo)
add_subdirectory(libfoo)

add_subdirectory(test/testcameraFactory)
add_test(NAME AllTestsInCameraFactory COMMAND testcameraFactory)

add_subdirectory(test/testcameraAdapter)
add_test(NAME AllTestsInCameraAdapter COMMAND testcameraAdapter)

add_subdirectory(lib/gmock)

include_directories(
    "lib/gmock/include"
    "raspiCamera/include"
    "include"
)

## Executables
set(MAIN_SOURCES
    main/main.cxx)

add_executable(NestCamera
    ${MAIN_SOURCES}
	       )

## Libraries
target_link_libraries(NestCamera ${raspicam_LIBS})

