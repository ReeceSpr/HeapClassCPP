cmake_minimum_required(VERSION 3.14)
project(Assignment_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(cmake-build-debug)

add_executable(Assignment_7
        .idea/.name
        ".idea/Assignment 7.iml"
        .idea/encodings.xml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        cmake-build-debug/Assignment_7
        cmake-build-debug/Assignment_7.cbp
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/random_N_10.txt
        cmake-build-debug/random_N_100.txt
        cmake-build-debug/random_N_25000.txt
        cmake-build-debug/random_N_5.txt
        cmake-build-debug/reversed_N_10.txt
        cmake-build-debug/reversed_N_100.txt
        cmake-build-debug/reversed_N_25000.txt
        cmake-build-debug/reversed_N_5.txt
        cmake-build-debug/sorted_N_10.txt
        cmake-build-debug/sorted_N_100.txt
        cmake-build-debug/sorted_N_25000.txt
        cmake-build-debug/sorted_N_5.txt
        CMakeLists.txt
        main.cpp)
