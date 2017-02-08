cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cpp/main.cpp hpp/ResourceHolder.h hpp/World.h hpp/SceneGraph.h cpp/World.cpp hpp/Game.h cpp/Game.cpp cpp/SceneGraph.cpp)
add_executable(game ${SOURCE_FILES})


set(SOURCE_LIB cpp/World.cpp)

add_library(World STATIC ${SOURCE_LIB})


set(SOURCE_LIB cpp/Game.cpp)

add_library(Game STATIC ${SOURCE_LIB})


set(SOURCE_LIB cpp/SceneGraph.cpp)

add_library(SceneGraph STATIC ${SOURCE_LIB})


# Define sources and executable
set(EXECUTABLE_NAME "MySFML")
add_executable(${EXECUTABLE_NAME} cpp/main.cpp)

target_link_libraries(${EXECUTABLE_NAME} Game World SceneGraph)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()