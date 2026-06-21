cmake_minimum_required(VERSION 3.24)
project(EclipseRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.4 REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_sources(${PROJECT_NAME} PRIVATE src/app/Window.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Vulkan::Vulkan
    fmt::fmt
    glfw
    glm::glm
    imgui::imgui
)