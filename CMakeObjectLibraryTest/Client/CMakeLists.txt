set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Client ${SOURCE_FILES})
target_link_libraries(Client DynamicLibrary)