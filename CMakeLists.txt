# Cmake Config that adds bindings support on IDEs.
# Note: This project should not use Cmake to perform the compilation of the project.
project(godot-game)
cmake_minimum_required(VERSION 3.20)

# Set the c++ standard to c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directories
set(GODOT_HEADERS_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../godot-cpp/godot-headers)
set(GODOT_INCLUDE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../godot-cpp/include)
set(GODOT_GEN_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../godot-cpp/include/gen)

# Source
file(GLOB_RECURSE SOURCE_CPP ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp)
file(GLOB_RECURSE SOURCE_H ${CMAKE_CURRENT_SOURCE_DIR}/**/*.h**)

add_library(${PROJECT_NAME} ${SOURCE_CPP} ${SOURCE_H})
target_include_directories(${PROJECT_NAME} PRIVATE ${GODOT_HEADERS_DIR} ${GODOT_INCLUDE_DIR} ${GODOT_GEN_DIR})