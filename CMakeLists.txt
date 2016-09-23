project(cplusplus)
cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 14)
add_executable(constexpr constexpr.cpp)
add_executable(constexpr_lookup constexpr_lookup.cpp)
add_executable(constexpr_c11_initarray constexpr_c11_initarray.cpp)
add_executable(utf utf_strings.cpp)

add_library(globalconfigLib STATIC globalconfig_lib.cpp)
add_executable(globalconfig globalconfig.cpp)
target_link_libraries(globalconfig globalconfigLib)
