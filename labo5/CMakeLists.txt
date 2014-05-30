cmake_minimum_required(VERSION 2.4)

SET(LABO "labo5")

PROJECT(${LABO})

# paths 
INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-O3 -Wall")
SET(CMAKE_CXX_LINK_FLAGS "-pg")
SET(OpenCV_LIBRARIES opencv_core opencv_highgui opencv_imgproc opencv_features2d)

FILE(GLOB FILES . src/*.cpp)
FOREACH (f ${FILES})

get_filename_component(filename ${f} NAME_WE)

ADD_EXECUTABLE(${filename} src/${filename}.cpp)
TARGET_LINK_LIBRARIES(${filename} ${OpenCV_LIBRARIES})

ENDFOREACH()


SET(CMAKE_BUILD_TYPE Debug)
