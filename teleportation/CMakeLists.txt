cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
project(quantum_teleportation LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(.)

find_package(CUDAQ REQUIRED)
set(CMAKE_CXX_COMPILER nvq++)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "--target nvidia")
add_executable(quantum_teleportation main.cpp)