## CMakeLists.txt
cmake_minimum_required(VERSION 2.8.7)
project(NestCamera)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/lib/cmake/)

## Raspberry Pi Setup
SET(HOST_MOUNTPOINT /mnt/pisquanch/)
SET(PI_INSTALL_PATH home/pi/NestCamera/build/)
SET(PI_TEST_INSTALL_PATH home/pi/NestCamera/test/bin)

## Libraries
SET(raspicam_DIR install_tools/raspicam-0.1.3/build)
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
    "include"
    "cameraFactory/include"
    "cameraAdapter/include"
    "videoAdapter/include"
)

## Executables
set(MAIN_SOURCES
    main/main.cxx
    cameraFactory/cameraFactory.cxx)


add_executable(NestCamera
    ${MAIN_SOURCES}
	       )

       install(TARGETS NestCamera 
    RUNTIME DESTINATION ${HOST_MOUNTPOINT}${PI_INSTALL_PATH})



## Libraries
target_link_libraries(NestCamera ${raspicam_LIBS})

