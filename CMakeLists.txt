cmake_minimum_required(VERSION 3.28.3 FATAL_ERROR)

set(PROJECT_NAME Things-done-cannot-be-undone)

project (${PROJECT_NAME})

add_executable(Things-done-cannot-be-undone src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)