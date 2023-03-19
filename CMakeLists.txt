cmake_minimum_required(VERSION 3.23)
project(tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_DIR external/glfw/)

set(RENDERER_SOURCES
        src/renderer/Renderer.h
        src/renderer/Renderer.cpp
        src/renderer/Material.h
        src/renderer/Provider.cpp
        src/renderer/Provider.h
        src/renderer/Text.cpp
        src/renderer/Text.h
        src/renderer/Character.h
        src/renderer/shader/Shader.cpp
        src/renderer/shader/Shader.h
        src/renderer/primitives/Colors.h
        src/renderer/primitives/Primitive.h
        src/renderer/primitives/TextPrimitive.cpp
        src/renderer/primitives/TextPrimitive.h
        src/renderer/primitives/cube/Cube.cpp
        src/renderer/primitives/cube/Cube.h
        src/renderer/primitives/line/LineMaterial.h
        src/renderer/primitives/line/Line.cpp
        src/renderer/primitives/line/Line.h
        src/renderer/camera/Camera.cpp
        src/renderer/camera/Camera.h
        src/renderer/stb_image.h
        )

add_library(renderer ${RENDERER_SOURCES})

target_include_directories(renderer PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/renderer>)

set(ENGINE_SOURCES
        src/engine/Transform.h
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/engine/GameObject.h
        src/engine/GameObject.cpp
        )

add_library(engine ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/engine>)

add_executable(tetris src/main.cpp
        src/game/Initializer.cpp
        src/game/Initializer.h
        src/game/GameController.cpp
        src/game/GameController.h
        src/game/TetrominoOrientations.h
        src/game/PiecePreview.cpp
        src/game/PiecePreview.h
        src/game/PiecePreview.cpp
        src/game/GameUI.cpp
        src/game/GameUI.h
        src/game/GameUI.cpp
        src/game/GameUI.cpp
        src/game/Grid/GridCell.h
        src/game/Grid/Board.cpp
        src/game/Grid/Board.h
        src/game/Grid/Piece.h
        src/game/Grid/Piece.cpp
        src/game/Grid/Tetromino.cpp
        src/game/Grid/Tetromino.h
        src/game/Grid/TetrominoData.h
        src/game/Input.cpp
        src/game/Input.h
        )

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/game>)

target_link_libraries(${PROJECT_NAME} PRIVATE engine)
target_link_libraries(${PROJECT_NAME} PRIVATE renderer)

# ADD GLAD
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(renderer PUBLIC glad)

# ADD GLM
add_subdirectory(external/glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)
target_link_libraries(renderer PUBLIC glm)
target_link_libraries(engine PUBLIC glm)

# ADD GLFW
add_subdirectory(${GLFW_DIR} ${GLFW_DIR}/src)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(renderer PUBLIC glfw)

# ADD OPENGL
FIND_PACKAGE(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL)

# ADD FREETYPE
SET(FT_DISABLE_HARFBUZZ ON)
SET(FT_DISABLE_PNG ON)
SET(FT_DISABLE_ZLIB ON)
SET(FT_DISABLE_BZIP2 ON)
SET(FT_DISABLE_BROTLI ON)

add_subdirectory(external/freetype)
target_include_directories(renderer PUBLIC external/freetype)
target_link_libraries(renderer PUBLIC freetype)

#ADD RESOURCES
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources
        COMMENT "Copying resources into binary directory")

add_dependencies(${PROJECT_NAME} copy_resources)
