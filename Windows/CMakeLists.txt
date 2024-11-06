cmake_minimum_required(VERSION 3.5)
project(xBuilder_Window C)

add_executable(${PROJECT_NAME} WIN32 xBuilder_Main.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

########################################################################################################################
## uiToolkit
set(UI_TOOLKIT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/uiToolkit)
file(GLOB UI_TOOLKIT_SOURCES ${UI_TOOLKIT_DIR}/*.c)
target_sources(${PROJECT_NAME} PUBLIC ${UI_TOOLKIT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${UI_TOOLKIT_DIR})

########################################################################################################################
## WIDGETS
set(MAIN_FRAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MainFrame)
file(GLOB MAIN_FRAME_SOURCES ${MAIN_FRAME_DIR}/*.c)
target_sources(${PROJECT_NAME} PUBLIC ${MAIN_FRAME_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${MAIN_FRAME_DIR})

set(PROJECT_VIEW_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ProjectView)
file(GLOB PROJECT_VIEW_SOURCES ${PROJECT_VIEW_DIR}/*.c)
target_sources(${PROJECT_NAME} PUBLIC ${PROJECT_VIEW_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_VIEW_DIR})

########################################################################################################################
## API
if(NOT TARGET xBuilder_API)
add_subdirectory(../API ${CMAKE_CURRENT_BINARY_DIR}/API)
endif ()
target_link_libraries(${PROJECT_NAME} PUBLIC xBuilder_API)
