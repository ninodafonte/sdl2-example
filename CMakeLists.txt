cmake_minimum_required(VERSION 3.30)
project(efectos_pec1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_OSX_ARCHITECTURES "arm64")

find_package(SDL2 REQUIRED)
find_library(SDL2_LIBRARY NAME SDL2)

add_executable(efectos_pec1 main.cpp utils/Timer.h utils/Timer.cpp)
include_directories(efectos_pec1 ${SDL2_INCLUDE_DIR})
target_link_libraries(efectos_pec1 ${SDL2_LIBRARIES})