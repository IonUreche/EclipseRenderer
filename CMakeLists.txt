cmake_minimum_required(VERSION 3.24)
project(EclipseRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/Dependencies.cmake)

add_executable(${PROJECT_NAME} src/main.cpp
src/App/Window.cpp
src/App/Window.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glm::glm
    imgui
)