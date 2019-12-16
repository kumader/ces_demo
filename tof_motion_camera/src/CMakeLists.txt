
add_definitions(-D_TARGET_ARCH_W32_)
file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

set(FILES
    stdafx.h
    tof_motion_camera_filter.h
    stdafx.cpp
    tof_motion_camera_filter.cpp
    ${HDRS}
    ${SRCS}
)

eb_add_dir_filter(tof_motion_camera ${DIR_NAME} ${FILES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Cfl_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/ColorMap_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Common_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/General_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Logger_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Mat2D_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/MLX75123_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Pgm_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Ppm_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/Rtl16_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/SocketIO_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/TcpFrame_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/tof_sdk_src/UdpFrame_inc/src
                    ${CMAKE_CURRENT_SOURCE_DIR}
)

eb_adtf_install_plugin(tof_motion_camera ./bin)
