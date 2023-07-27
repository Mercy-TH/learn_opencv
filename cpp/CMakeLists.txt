cmake_minimum_required(VERSION 3.0)
project(learn_opencv)
add_definitions(-std=c++11)
option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main
        ${OpenCV_LIBS})

add_definitions(-O2 -pthread)

