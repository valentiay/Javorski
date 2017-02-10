cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES cpp/main.cpp cpp/Action.cpp cpp/Command.cpp cpp/Game.cpp cpp/Player.cpp cpp/SceneGraph.cpp cpp/World.cpp hpp/Action.h hpp/Command.h hpp/Game.h hpp/Player.h hpp/ResourceHolder.h hpp/SceneGraph.h hpp/World.h)
add_executable(game ${SOURCE_FILES})

set(SOURCE_LIB cpp/World.cpp cpp/Action.cpp cpp/Command.cpp cpp/Game.cpp cpp/Player.cpp cpp/SceneGraph.cpp)

add_library(valentiay STATIC ${SOURCE_LIB})


# Define sources and executable
set(EXECUTABLE_NAME "MySFML")
add_executable(${EXECUTABLE_NAME} cpp/main.cpp)

target_link_libraries(${EXECUTABLE_NAME} valentiay)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()