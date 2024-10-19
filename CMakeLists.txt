cmake_minimum_required(VERSION 3.5)
project(xBuilder C)

if (NOT TARGET xBuilder_API)
add_subdirectory(API)
endif ()

add_subdirectory(Windows)



