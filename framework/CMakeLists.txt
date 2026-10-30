cmake_minimum_required(VERSION 3.10)
project(graphite_framework LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE GRAPHITE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(graphite_framework STATIC ${GRAPHITE_SOURCES})

target_include_directories(graphite_framework PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
