cmake_minimum_required(VERSION 3.20)
project(flightlab LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)
include(CTest)

add_library(flightlab_core STATIC src/safe_mode.cpp)
target_include_directories(flightlab_core PUBLIC src)
target_compile_features(flightlab_core PUBLIC cxx_std_20)

add_executable(flightlab src/main.cpp)
target_link_libraries(flightlab PRIVATE flightlab_core)

if(BUILD_TESTING)
    add_executable(safe_mode_test tests/safe_mode_test.cpp)
    target_link_libraries(safe_mode_test PRIVATE flightlab_core)
    target_compile_options(safe_mode_test PRIVATE -UNDEBUG)
    add_test(NAME safe_mode COMMAND safe_mode_test)
endif()

