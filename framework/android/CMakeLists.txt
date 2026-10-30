# CMakeLists.txt - Android NDK build for Graphite native library
cmake_minimum_required(VERSION 3.10)
project(graphite_native)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
add_library(graphite_native SHARED
    graphite_native.cpp
)

# Include directories
target_include_directories(graphite_native PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries
target_link_libraries(graphite_native
    log
    android
)

# Compiler flags
target_compile_options(graphite_native PRIVATE
    -Wall
    -Wextra
    -O2
    -fvisibility=hidden
)

# Android-specific
if(ANDROID)
    set_target_properties(graphite_native PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/${ANDROID_ABI}
    )
endif()
