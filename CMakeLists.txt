cmake_minimum_required(VERSION 3.8)
project("MagnetarVoIP" C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)
set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE true)

set(OUTPUT_ELF
  "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.out"
  )

set(TARGET_ARCH "linux_arm")

set(SRC_FILES
  ${CMAKE_SOURCE_DIR}/src/audio/aio_capture.c
  ${CMAKE_SOURCE_DIR}/src/audio/aio_playback.c

  ${CMAKE_SOURCE_DIR}/src/chat/cht_main.cc
  ${CMAKE_SOURCE_DIR}/src/chat/cht_packing.c

  ${CMAKE_SOURCE_DIR}/src/core/core.c
  ${CMAKE_SOURCE_DIR}/src/core/core_thread.c

  ${CMAKE_SOURCE_DIR}/src/init/init.cc
  ${CMAKE_SOURCE_DIR}/src/init/init_miniaudio.c
  ${CMAKE_SOURCE_DIR}/src/init/init_network.cc
  ${CMAKE_SOURCE_DIR}/src/init/init_externs.cc

  ${CMAKE_SOURCE_DIR}/src/lib/linenoise/ConvertUTF.cpp
  ${CMAKE_SOURCE_DIR}/src/lib/linenoise/linenoise.cpp
  ${CMAKE_SOURCE_DIR}/src/lib/linenoise/wcwidth.cpp

  ${CMAKE_SOURCE_DIR}/src/lib/miniaudio/miniaudio.c

  ${CMAKE_SOURCE_DIR}/src/networking/nw_packer.cc
  ${CMAKE_SOURCE_DIR}/src/networking/nw_client.c
  ${CMAKE_SOURCE_DIR}/src/networking/nw_server.c
  ${CMAKE_SOURCE_DIR}/src/networking/nw_send_rtp.c
  ${CMAKE_SOURCE_DIR}/src/networking/nw_recv_rtp.c
  ${CMAKE_SOURCE_DIR}/src/networking/nw_tcp.c
  ${CMAKE_SOURCE_DIR}/src/networking/nw_rertcp.c

  ${CMAKE_SOURCE_DIR}/src/ux/ux_main.c
  ${CMAKE_SOURCE_DIR}/src/ux/ux_interface.c

  ${CMAKE_SOURCE_DIR}/src/ux/cli/cli_interface.c
  ${CMAKE_SOURCE_DIR}/src/ux/cli/cli_interpret.c

  #${CMAKE_SOURCE_DIR}/src/etc/queue.cc
  )

#find_package(PkgConfig REQUIRED)
find_package(libre CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
#pkg_check_modules(GST REQUIRED gstreamer-1.0)
#pkg_check_modules(GST_RTP REQUIRED gstreamer-plugins-base-1.0)

include_directories(
  include ${CMAKE_SOURCE_DIR}/include/lib
  include ${CMAKE_SOURCE_DIR}/include/lib/re
  include ${CMAKE_SOURCE_DIR}/include/lib/klib
  include ${CMAKE_SOURCE_DIR}/include/magnetarvoip
  #  ${GST_INCLUDE_DIRS}
  #  ${GST_RTP_INCLUDE_DIRS}
  )

add_compile_options( -Wall )

link_libraries(
  crypto
  ssl
  re
  opus
  ncursesw
  cpp-optparse
)
link_directories(
  ${CMAKE_SOURCE_DIR}/lib/${TARGET_ARCH}
  #${GST_LIBRARY_DIRS}
  #${GST_RTP_LIBRARY_DIRS}
)

#if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64" OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES "i386")
#  if(WIN32)
#    link_directories(
#      ${CMAKE_SOURCE_DIR}/lib/windows
#    )
#  endif()
#  if(LINUX)
#    link_directories(
#      ${CMAKE_SOURCE_DIR}/lib/linux
#    )
#  endif()
#endif()
#if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
#  if(LINUX)
#    link_directories(
#      ${CMAKE_SOURCE_DIR}/lib/linux_arm
#    )
#  endif()
#endif()

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${TARGET_ARCH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

add_executable(
  ${OUTPUT_ELF}
  ${SRC_FILES}
  )

target_link_libraries(
  ${OUTPUT_ELF}
  OpenSSL::SSL
  #${GST_LIBRARIES}
  #${GST_RTP_LIBRARIES}
)
