cmake_minimum_required(VERSION 3.24)
project(EclipseRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/Dependencies.cmake)

add_executable(${PROJECT_NAME} src/main.cpp)
target_sources(${PROJECT_NAME} PRIVATE src/app/Window.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glm::glm
    imgui
)

find_package(Vulkan REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)