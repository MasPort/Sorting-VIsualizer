cmake_minimum_required(VERSION 3.23)

project(SortVis)

include(FetchContent)

set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES
    src/main.cpp
    src/Visualizer.cpp
    src/Slider.cpp
    src/Window.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)

set(INCLUDE_DIRECTORY include/)
set(HEADER_FILES ${INCLUDE_DIRECTORY}/Visualizer.hpp)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INCLUDE_DIRECTORY}
)
