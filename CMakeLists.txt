cmake_minimum_required(VERSION 3.23)
project(tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_DIR /home/gmek/Dev/C++/Dependencies/glfw/)

add_executable(tetris src/main.cpp src/renderer/Renderer.h src/renderer/Renderer.cpp src/renderer/shader/Shader.cpp src/renderer/shader/Shader.h src/Transform.h src/camera/Camera.cpp src/camera/Camera.h src/debug/Debug.h src/renderer/primitives/Primitive.h src/renderer/primitives/cube/Cube.cpp src/renderer/primitives/cube/Cube.h src/renderer/Material.h src/engine/Engine.cpp src/engine/Engine.h src/renderer/primitives/line/Line.cpp src/renderer/primitives/line/Line.h src/renderer/primitives/Colors.h src/renderer/primitives/line/LineMaterial.h src/game/GameCube.cpp src/game/GameCube.h src/game/GameObject.h src/renderer/Provider.cpp src/renderer/Provider.h src/game/MovingCube.cpp src/game/MovingCube.h src/game/Initializer.cpp src/game/Initializer.h src/game/GameObject.cpp src/game/Grid.cpp src/game/Grid.h)

# ADD GLAD
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)

# ADD GLM
add_subdirectory(external/glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)

# ADD GLFW
add_subdirectory(${GLFW_DIR}
        ${GLFW_DIR}/src)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

# ADD OPENGL
FIND_PACKAGE(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)

