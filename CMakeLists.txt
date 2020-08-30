cmake_minimum_required(VERSION 3.15)
project(particles)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_PREFIX_PATH "C:\\Users\\robin\\Developer\\SDL2-2.0.12")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
message(SDL2_INCLUDE_DIRS "  " ${SDL2_INCLUDE_DIRS})

add_executable(particles main.cpp Test.cxx Test.h)
target_link_libraries(particles ${SDL2_LIBRARIES})
