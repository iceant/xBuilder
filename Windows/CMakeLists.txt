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
set(WIDGET_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Widgets)
file(GLOB WIDGET_SOURCES ${WIDGET_DIR}/*.c)
file(GLOB WIDGET_RC_SOURCES ${WIDGET_DIR}/*.rc)
target_sources(${PROJECT_NAME} PUBLIC ${WIDGET_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${WIDGET_DIR})
target_sources(${PROJECT_NAME} PUBLIC ${WIDGET_RC_SOURCES})


########################################################################################################################
## API
if(NOT TARGET xBuilder_API)
add_subdirectory(../API ${CMAKE_CURRENT_BINARY_DIR}/API)
endif ()
target_link_libraries(${PROJECT_NAME} PUBLIC xBuilder_API)
