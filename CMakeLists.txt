cmake_minimum_required(VERSION 3.22)
project(oglrender)
set(CMAKE_CXX_STANDARD 20)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(main)

add_link_options( -framework OpenGL)

aux_source_directory(./src sources)
target_sources(main PUBLIC ${sources})

find_package(glfw3  REQUIRED)
target_link_libraries(main PUBLIC glfw "-framework OpenGL")

#find_package(glm REQUIRED)
#target_link_libraries(main PUBLIC glm)

add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)
target_link_libraries(main PUBLIC glad)

file(GLOB IMGUI_SOURCES CONFIGURE_DEPENDS libs/imgui/src/*.cpp)
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC libs/imgui/include)


target_link_libraries(main PUBLIC imgui)