cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


add_executable(image_processor_4
        image_processor.cpp
        Image.cpp BMP.cpp
        filters.cpp
        filter_crop.cpp
        filter_edge_detection.cpp
        filter_negative.cpp
        filter_sharpening.cpp
        filter_blur.cpp
        filter_grayscale.cpp
        )
