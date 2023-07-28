cmake_minimum_required(VERSION 3.0)
project(learn_opencv)
add_definitions(-std=c++11)
option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)


if(CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    message("current platform: Linux ")
elseif(CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    message("current platform: Windows ")
    set(OpenCV_DIR "D:\\opencv\\mingw_build\\install")
else()
    message("current platform: unkonw ")
endif()

# opencv-4.6.0
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

message(STATUS "OpenCV库: ${OpenCV_LIBS}")
message(STATUS "OpenCV版本: ${OpenCV_VERSION}")
message(STATUS "OpenCV路径： ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_DIR:　${OpenCV_DIR}")

add_executable(main main.cpp)
target_link_libraries(main
        ${OpenCV_LIBS})

add_definitions(-O2 -pthread)

