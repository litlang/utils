cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(trie)

file(GLOB_RECURSE SOURCES "implement/*.cpp")
add_library(${PROJECT_NAME} INTERFACE)

install(DIRECTORY include/ DESTINATION ${PROJECT_NAME}/include)