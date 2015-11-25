set(RASPICAMERA_SOURCES
    raspiCamera.cpp)

include_directories("include")

add_library(raspiCamera
    ${RASPICAMERA_SOURCES}
)
