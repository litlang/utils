cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ranges)

file(GLOB_RECURSE SOURCES "implement/*.cpp")
add_library(${PROJECT_NAME}_STATIC STATIC ${SOURCES})
add_library(${PROJECT_NAME}_SHARED SHARED ${SOURCES})

set_target_properties(${PROJECT_NAME}_STATIC PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_SHARED PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}_STATIC PUBLIC include)
target_include_directories(${PROJECT_NAME}_SHARED PUBLIC include)

install(
	TARGETS ${PROJECT_NAME}_STATIC ${PROJECT_NAME}_SHARED
	LIBRARY DESTINATION ${PROJECT_NAME}/lib
	ARCHIVE DESTINATION ${PROJECT_NAME}/lib
)
install(DIRECTORY include/ DESTINATION ${PROJECT_NAME}/include)