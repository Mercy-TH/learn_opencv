cmake_minimum_required(VERSION 3.0)
project(learn_opencv)
add_definitions(-std=c++11)
option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# opencv-4.6.0
set(OpenCV_DIR "D:\\opencv\\mingw_build\\install")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

message(STATUS "OpenCV库: ${OpenCV_LIBS}")
message(STATUS "OpenCV版本: ${OpenCV_VERSION}")
message(STATUS "OpenCV路径： ${OpenCV_INCLUDE_DIRS}")

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

add_executable(main main.cpp)
target_link_libraries(main
        ${OpenCV_LIBS})

add_definitions(-O2 -pthread)

