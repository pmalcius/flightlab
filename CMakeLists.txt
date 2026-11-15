cmake_minimum_required(VERSION 3.20)
project(flightlab LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(flightlab src/main.cpp)
target_compile_features(flightlab PRIVATE cxx_std_20)
target_compile_options(flightlab PRIVATE -Wall -Wextra -Wpedantic)
