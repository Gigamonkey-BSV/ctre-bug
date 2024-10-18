cmake_minimum_required(VERSION 3.29)
project(ctretest)

set(CMAKE_CXX_STANDARD 23)
include (FetchContent)
FetchContent_Declare (ctre URL https://github.com/hanickadot/compile-time-regular-expressions/archive/refs/tags/v3.9.0.zip)
FetchContent_MakeAvailable (ctre)

add_executable(ctretest main.cpp)
target_link_libraries(ctretest ctre)