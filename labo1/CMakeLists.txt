cmake_minimum_required(VERSION 2.4)

SET(LABO "labo1")

PROJECT(${LABO})

# paths 
#INCLUDE_DIRECTORIES(src)
#INCLUDE_DIRECTORIES(/usr/local/include)
#LINK_DIRECTORIES(/usr/local/lib)
#LINK_DIRECTORIES(/usr/lib)

find_package(OpenCV REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-o3 -w")
SET(CMAKE_CXX_LINK_FLAGS "-pg")
SET(OpenCV_LIBRARIES opencv_core opencv_highgui opencv_imgproc)

ADD_EXECUTABLE(tibault_damman_${LABO} src/tibault_damman_opgave1.cpp)
TARGET_LINK_LIBRARIES(tibault_damman_${LABO} ${OpenCV_LIBRARIES})

SET(CMAKE_BUILD_TYPE Release)
