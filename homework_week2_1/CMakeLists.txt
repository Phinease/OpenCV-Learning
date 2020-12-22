cmake_minimum_required(VERSION 3.17)
project(homework_week2_1)

set(CMAKE_CXX_STANDARD 14)

if(MSVC)
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable(homework_week2_1 main.cpp)
TARGET_LINK_LIBRARIES(homework_week2_1 ${OpenCV_LIBS} )