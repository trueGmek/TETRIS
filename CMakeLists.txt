cmake_minimum_required(VERSION 3.23)
project(tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_DIR /home/gmek/Dev/C++/Dependencies/glfw/)

add_executable(tetris src/main.cpp src/renderer/Renderer.h src/renderer/Renderer.cpp src/renderer/Primitives.h src/renderer/shader/Shader.cpp src/renderer/shader/Shader.h)

# ADD GLFW
add_subdirectory(${GLFW_DIR}
        ${GLFW_DIR}/src)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

FIND_PACKAGE(OpenGL REQUIRED)

# ADD GLAD
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

