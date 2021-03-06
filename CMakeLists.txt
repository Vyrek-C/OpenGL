cmake_minimum_required(VERSION 3.10)
project(cmOpenGL)

include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCE src/*.cpp)
add_executable(cmOpenGL ${SOURCE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includeFiles)
set(GLFW_LIB ${CMAKE_CURRENT_SOURCE_DIR}/glfw3.lib)

set_target_properties(cmOpenGL PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE IMGUISRC ${INCLUDE_DIR}/imgui/*.cpp)

include_directories(includeFiles)

find_package(OpenGL)
add_library(glad STATIC "src/glad.c")
add_library(imgui STATIC ${IMGUISRC})

target_link_libraries(cmOpenGL PUBLIC glad ${GLFW_LIB} imgui)

include(CPack)