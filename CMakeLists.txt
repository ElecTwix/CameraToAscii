cmake_minimum_required(VERSION 3.16.3)
project(CameraToAscii)



find_package(OpenCV CONFIG REQUIRED)




add_executable(CameraToAscii main.cpp)
target_link_libraries(CameraToAscii PRIVATE opencv_ml opencv_dnn opencv_core opencv_flann opencv_videoio opencv_highgui)
