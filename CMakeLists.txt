#cmake_minimum_required(VERSION 3.17)
#project(opencv_webcam)

#set(CMAKE_CXX_STANDARD 20)

# Where to find CMake modules and OpenCV
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

#add_executable(opencv_webcam driver.cpp capture.cpp capture.h)

# add libs you need
#set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

# linking
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


cmake_minimum_required(VERSION 3.17)
project(opencv_webcam)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

add_executable(opencv_webcam driver.cpp capture.cpp capture.h TCP_Server.h TCP_Server.cpp)
target_link_libraries(opencv_webcam ${OpenCV_LIBS})
