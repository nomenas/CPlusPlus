cmake_minimum_required(VERSION 3.9)
project(boost_signals)

find_package(boost REQUIRED)
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=thread -g" )
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread -g" )

add_executable(boost_signals main.cpp)
target_include_directories(boost_signals PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(boost_signals GTest::GTest)