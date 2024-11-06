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

##############################################################################################################
## TEST
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.t.c)
foreach (item IN LISTS TEST_SOURCES)
    get_filename_component(TestUnit ${item} NAME_WLE)
    message(STATUS "[${PROJECT_NAME}] TEST_SOURCES: ${TestUnit} - ${item}")
    add_executable(${TestUnit} ${item})
    target_link_libraries(${TestUnit} PRIVATE ${PROJECT_NAME})
endforeach ()