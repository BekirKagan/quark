cmake_minimum_required(VERSION 3.31)
project(denovo-allocator-examples)

add_executable(demo ${PROJECT_SOURCE_DIR}/demo/demo.c)
target_link_libraries(demo PRIVATE ${CMAKE_PROJECT_NAME})
