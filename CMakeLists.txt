cmake_minimum_required(VERSION 3.12)
project(ApolloEngine)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/Apollo/Application src/Apollo/Application src/Apollo/Core src/Apollo src/Apollo/EntryPoint src/Apollo/Logger src/Apollo/event/IEvents src/Apollo/event/EventSystem src/Apollo/window/Events src/Apollo/window/Window src/Apollo/input/InputEvents src/Apollo/render/IRenderable)

if (UNIX AND NOT APPLE)
    add_compile_definitions(APOLLO_PLATFORM_LINUX)
endif()

include_directories(lib/GSTL/src lib/gl3w/include lib/mglib src)

add_subdirectory(lib/GSTL)

add_library(ApolloEngine SHARED ${SOURCE_FILES} lib/gl3w/src/gl3w)

target_link_libraries(ApolloEngine GSTL GL glfw)

add_subdirectory(src/Grawler)