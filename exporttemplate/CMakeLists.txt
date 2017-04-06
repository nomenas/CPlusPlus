cmake_minimum_required(VERSION 3.6)
project(exporttemplate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LIB_SOURCE_FILES container.cpp api.h MyType.cpp Pimpl.cpp)
add_library(lib STATIC ${LIB_SOURCE_FILES})

set(SOURCE_FILES main.cpp test.cpp)
add_executable(exporttemplate ${SOURCE_FILES})
target_link_libraries(exporttemplate lib)
target_compile_definitions(exporttemplate PRIVATE TEST_MYTYPE2_PRIV)