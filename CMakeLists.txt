cmake_minimum_required(VERSION 3.22)
project(oglrender)
set(CMAKE_CXX_STANDARD 20)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(main src/renderer/VertexArray.cpp src/renderer/VertexArray.h src/renderer/VertexBufferLayout.cpp src/renderer/VertexBufferLayout.h)

add_link_options( -framework OpenGL)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.h)
target_sources(main PUBLIC ${sources})

find_package(glfw3  REQUIRED)
target_link_libraries(main PUBLIC glfw "-framework OpenGL")

#rest
#find_package(glm REQUIRED)
#target_link_libraries(main PUBLIC glm)

add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)
target_link_libraries(main PUBLIC glad)

file(GLOB IMGUI_SOURCES CONFIGURE_DEPENDS libs/imgui/src/*.cpp)
add_library(im_gui STATIC ${IMGUI_SOURCES})
target_include_directories(im_gui PUBLIC libs/imgui/include)
target_link_libraries(main PUBLIC im_gui)

add_custom_target(copy_res ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/res/
        ${PROJECT_BINARY_DIR}/res/
        COMMENT "copying")

#file(GLOB shader_files res/shaders/*)
# message(${shader_files})
## Define a custom target to copy the files
#add_custom_target(copy_res ALL
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        ${shader_files}
#        $<TARGET_FILE_DIR:main>/res/shaders/
#        COMMENT "copying")

# Add the custom target as a dependency of my_target
add_dependencies(main copy_res)
