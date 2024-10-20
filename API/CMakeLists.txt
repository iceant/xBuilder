cmake_minimum_required(VERSION 3.5)
project(xBuilder_API C)

add_library(${PROJECT_NAME} "")
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

########################################################################################################################
## SOURCES
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB SOURCES ${SOURCES_DIR}/*.c)
target_sources(${PROJECT_NAME} PUBLIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SOURCES_DIR})

foreach (item IN LISTS SOURCES)
    message(STATUS "[${PROJECT_NAME}] SOURCES: ${item}")
endforeach ()

########################################################################################################################
## SDK
if(NOT TARGET SDK)
    add_subdirectory(../SDK ${CMAKE_CURRENT_BINARY_DIR}/SDK)
endif ()
target_link_libraries(${PROJECT_NAME} PUBLIC SDK)

